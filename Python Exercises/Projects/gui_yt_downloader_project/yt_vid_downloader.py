"""YouTube Video Downloader using yt-dlp and Tkinter"""
import tkinter as tk
from tkinter import filedialog, messagebox, scrolledtext
from pathlib import Path
import subprocess
import threading
import yt_dlp


class YTDownloaderApp(tk.Tk):
    """A simple GUI application for downloading YouTube videos."""
    def __init__(self):
        """Initialize the main application window."""
        super().__init__()
        self.title("YouTube Video Downloader")
        self.geometry("600x400")

        self.url_var = tk.StringVar()
        self.output_dir = Path.cwd()
        self.cookies_path = None
        self.keep_originals = tk.BooleanVar(value=False)

        self.create_widgets()

    def create_widgets(self):
        """Create and place widgets in the main window."""
        tk.Label(
            self, text="YouTube Video URL:"
        ).pack(anchor='w', padx=10, pady=(10, 0))
        tk.Entry(self, textvariable=self.url_var, width=70).pack(padx=10)

        tk.Button(
            self, text="Choose Output Directory",
            command=self.select_output_dir
        ).pack(pady=5)
        tk.Button(
            self, text="Choose cookies.txt (optional)",
            command=self.select_cookies_file
        ).pack(pady=5)
        tk.Checkbutton(
            self,
            text="Keep original downloaded files",
            variable=self.keep_originals
        ).pack(pady=2)

        tk.Button(
            self, text="Start Download", command=self.start_download_thread
        ).pack(pady=10)

        self.log = scrolledtext.ScrolledText(self, height=10, state='disabled')
        self.log.pack(fill='both', expand=True, padx=10, pady=10)

    def select_output_dir(self):
        """Open a dialog to select the output directory."""
        directory = filedialog.askdirectory()
        if directory:
            self.output_dir = Path(directory).expanduser().resolve()
            self.log_message(f"Output directory set to: {self.output_dir}")

    def select_cookies_file(self):
        """Open a dialog to select the cookies.txt file."""
        file_path = filedialog.askopenfilename(
            filetypes=[("Cookies file", "*.txt")]
        )
        if file_path:
            self.cookies_path = str(Path(file_path).expanduser().resolve())
            self.log_message(f"Using cookies file: {self.cookies_path}")

    def start_download_thread(self):
        """Start the video download in a separate thread."""
        threading.Thread(target=self.download_video, daemon=True).start()

    def log_message(self, message):
        """Log messages to the scrolled text widget."""
        self.log.config(state='normal')
        self.log.insert(tk.END, message + "\n")
        self.log.see(tk.END)
        self.log.config(state='disabled')

    def download_video(self):
        """Download the video from the provided URL."""
        url = self.url_var.get().strip()
        if not url:
            messagebox.showerror("Error", "Please enter a valid YouTube URL.")
            return

        ydl_opts = {
            'format': 'bestvideo+bestaudio/best',
            'outtmpl': str(self.output_dir / '%(title)s.%(ext)s'),
            'restrictfilenames': True
        }

        if self.keep_originals.get():
            self.log_message(
                "Option enabled: Keeping original downloaded files."
            )
        else:
            self.log_message(
                "Option disabled: Original files will be "
                "deleted after merging."
            )

        if self.cookies_path:
            ydl_opts['cookiefile'] = self.cookies_path

        try:
            with yt_dlp.YoutubeDL(ydl_opts) as ydl:
                self.log_message("Downloading...")
                result = ydl.extract_info(url, download=True)
                filename = ydl.prepare_filename(result)
                self.log_message(f"Downloaded to: {filename}")

            if not filename.endswith('.mp4'):
                mp4_file = Path(filename).with_suffix('.mp4')
                self.log_message(f"Converting to MP4: {mp4_file.name}")
                subprocess.run([
                    'ffmpeg', '-y',
                    '-loglevel', 'fatal',
                    '-i', filename,
                    '-c:v', 'copy',
                    '-c:a', 'aac',
                    '-b:a', '320k',
                    str(mp4_file)
                ], check=True)
                self.log_message(f"Conversion complete: {mp4_file.name}")
                if not self.keep_originals.get():
                    try:
                        Path(filename).unlink()
                        self.log_message(f"Deleted original file: {filename}")
                    except OSError as e:
                        self.log_message(f"Error deleting original file: {e}")
                else:
                    self.log_message(
                        "Original file retained as per user preference."
                    )
        except yt_dlp.utils.DownloadError as e:
            self.log_message(f"Download failed: {e}")
        except yt_dlp.utils.UnsupportedError as e:
            self.log_message(f"Unsupported URL: {e}")
        except yt_dlp.utils.GeoRestrictedError as e:
            self.log_message(f"Geo-restricted content: {e}")
        except yt_dlp.utils.ExtractorError as e:
            self.log_message(f"Extractor error: {e}")
        except subprocess.CalledProcessError as e:
            self.log_message(f"FFmpeg conversion failed: {e}")
        except FileNotFoundError as e:
            self.log_message(f"FFmpeg not found: {e}")


def main():
    """Run the YouTube Video Downloader application."""
    app = YTDownloaderApp()
    app.mainloop()


if __name__ == "__main__":
    main()
