"""YouTube Video Downloader using yt-dlp
   Requires ffmpeg for audio/video merging (separately installed)
"""
from pathlib import Path
import subprocess
import yt_dlp


def get_output_directory():
    """Prompt user for output directory;
       default to current directory if blank.
    """
    while True:
        try:
            user_dir = input(
                "Enter output directory for downloaded video "
                "(leave blank for current directory): "
            ).strip()
            output_dir = (
                Path(user_dir).expanduser().resolve()
                if user_dir else Path.cwd()
            )
            output_dir.mkdir(parents=True, exist_ok=True)
            return output_dir
        except (OSError, ValueError) as e:
            print(f"Error with directory: {e}. Please try again.")
        except KeyboardInterrupt:
            print("\nDirectory input cancelled by user. Exiting...")
            exit(1)
        except EOFError:
            print("\nNo input received. Exiting...")
            exit(1)


def get_video_url():
    """Prompt user for YouTube video URL."""
    while True:
        try:
            url = input("Enter URL of YT video: ").strip()
            if not url:
                print("URL cannot be empty.")
                continue
            return url
        except KeyboardInterrupt:
            print("\nURL input cancelled by user. Exiting...")
            exit(1)
        except EOFError:
            print("\nNo input received. Exiting...")
            exit(1)


# This requires a cookies.txt file from browser in netscape format
# Must download cookies.txt separately.
def get_cookies_path():
    """Prompt user for cookies.txt file path, optional."""
    try:
        path = input(
            "Enter path to cookies.txt file (leave blank if not needed): "
        ).strip()
        if path:
            try:
                cookies_file = Path(path).expanduser().resolve()
                if not cookies_file.is_file():
                    print(f"Cookies file not found at: {cookies_file}")
                    return None
                return str(cookies_file)
            except (OSError, ValueError) as e:
                print(f"Cookies file not found or not a regular file: {e}")
                return None
        return None
    except (KeyboardInterrupt, EOFError):
        print(
            "\nCookies input cancelled by user "
            " or no input received. Continuing "
            " without cookies."
        )
        exit(1)


def download_video(url, output_dir, cookies_path=None):
    """Download YouTube video at given URL to the specified directory."""
    ydl_opts = {
        'format': 'bestvideo+bestaudio/best',
        'outtmpl': str(output_dir / '%(title)s.%(ext)s'),
        'restrictfilenames': True
    }
    if cookies_path:
        ydl_opts['cookiefile'] = cookies_path
    try:
        with yt_dlp.YoutubeDL(ydl_opts) as ydl:
            result = ydl.extract_info(url, download=True)
            filename = ydl.prepare_filename(result)
        print(f"\nDownload complete!\nSaved to: {output_dir}")
        if not filename.endswith('.mp4'):
            mp4_file = Path(filename).with_suffix('.mp4')
            print(f"Converting to MP4: {mp4_file.name}")
            subprocess.run([
                'ffmpeg', '-y',
                '-loglevel', 'fatal',
                '-i', filename,
                '-c:v', 'copy',
                '-c:a', 'aac',
                '-b:a', '320k',
                str(mp4_file)
            ], check=True)
            print(f"Conversion complete: {mp4_file.name}")
            while True:
                delete_original = input(
                    "Do you want to delete the original file? (y/n): "
                ).strip().lower()
                if delete_original == 'y':
                    try:
                        Path(filename).unlink()
                        print(f"Deleted original file: {filename}")
                    except OSError as e:
                        print(f"Error deleting original file: {e}")
                    break
                elif delete_original == 'n':
                    print("Original file retained.")
                    break
                else:
                    print("Invalid input. Please enter 'y' or 'n'.")
    except yt_dlp.utils.DownloadError as e:
        print(f"\nDownload failed: {e}")
    except yt_dlp.utils.UnsupportedError as e:
        print(f"\nUnsupported video or URL: {e}")
    except yt_dlp.utils.ExtractorError as e:
        print(f"\nFailed to extract video info: {e}")
    except subprocess.CalledProcessError as e:
        print(f"\nFFmpeg conversion failed: {e}")
    except OSError as e:
        print(f"\nError deleting original file: {e}")
    except KeyboardInterrupt:
        print("\nDownload interrupted by user. Exiting...")
        exit(1)


def main():
    """Main function to run the YouTube video downloader."""
    try:
        url = get_video_url()
        output_dir = get_output_directory()
        cookies_path = get_cookies_path()
        download_video(url, output_dir, cookies_path)
    except KeyboardInterrupt:
        print("\nProgram interrupted by user. Exiting...")
        exit(1)


if __name__ == "__main__":
    main()
