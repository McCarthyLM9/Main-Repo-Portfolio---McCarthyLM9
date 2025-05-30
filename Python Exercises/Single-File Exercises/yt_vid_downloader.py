"""YouTube Video Downloader using yt-dlp
   Requires ffmpeg for audio/video merging (separately installed)
"""
from pathlib import Path
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


def download_video(url, output_dir):
    """Download YouTube video at given URL to the specified directory."""
    ydl_opts = {
        'format': 'bestvideo+bestaudio/best',
        'outtmpl': str(output_dir / '%(title)s.%(ext)s'),
    }
    try:
        with yt_dlp.YoutubeDL(ydl_opts) as ydl:
            ydl.download([url])
        print(f"\nDownload complete!\nSaved to: {output_dir}")
    except yt_dlp.utils.DownloadError as e:
        print(f"\nDownload failed: {e}")
    except yt_dlp.utils.UnsupportedError as e:
        print(f"\nUnsupported video or URL: {e}")
    except yt_dlp.utils.ExtractorError as e:
        print(f"\nFailed to extract video info: {e}")
    except KeyboardInterrupt:
        print("\nDownload interrupted by user. Exiting...")
        exit(1)


def main():
    """Main function to run the YouTube video downloader."""
    try:
        url = get_video_url()
        output_dir = get_output_directory()
        download_video(url, output_dir)
    except KeyboardInterrupt:
        print("\nProgram interrupted by user. Exiting...")
        exit(1)


if __name__ == "__main__":
    main()
