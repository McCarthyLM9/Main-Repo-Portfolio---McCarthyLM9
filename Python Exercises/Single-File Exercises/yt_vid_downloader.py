"""YouTube Video Downloader using yt-dlp"""
from pathlib import Path
import yt_dlp


def get_output_directory():
    """Prompt user for output directory;
       default to current directory if blank.
    """
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


def get_video_url():
    """Prompt user for YouTube video URL."""
    url = input("Enter URL of YT video: ").strip()
    return url


def download_video(url, output_dir):
    """Download YouTube video at given URL to the specified directory."""
    ydl_opts = {
        'format': 'best',
        'outtmpl': str(output_dir / '%(title)s.%(ext)s'),
    }
    with yt_dlp.YoutubeDL(ydl_opts) as ydl:
        ydl.download([url])
    print(f"\nDownload complete!\nSaved to: {output_dir}")


def main():
    """Main function/method to run the YouTube video downloader."""
    url = get_video_url()
    output_dir = get_output_directory()
    download_video(url, output_dir)


if __name__ == "__main__":
    main()
