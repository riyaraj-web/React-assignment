import os
import shutil
from tqdm import tqdm
from datetime import datetime
import sys

# ---------------------------------------------------------
# File System Organizer
# ---------------------------------------------------------
# This script organizes files in a given directory
# into categorized folders such as Images, Videos, Documents, etc.
# ---------------------------------------------------------


# Define file type categories
CATEGORIES = {
    "Images": [".jpg", ".jpeg", ".png", ".gif", ".bmp", ".svg"],
    "Videos": [".mp4", ".mkv", ".mov", ".avi", ".flv", ".wmv"],
    "Documents": [".pdf", ".docx", ".doc", ".txt", ".pptx", ".xlsx"],
    "Code": [".py", ".js", ".cpp", ".java", ".html", ".css", ".ts"],
    "Archives": [".zip", ".rar", ".7z", ".tar", ".gz"],
    "Audio": [".mp3", ".wav", ".flac", ".m4a"]
}

LOG_FILE = "organizer_log.txt"


def get_category(filename):
    """Return the category of a file based on its extension."""
    _, ext = os.path.splitext(filename.lower())
    for category, extensions in CATEGORIES.items():
        if ext in extensions:
            return category
    return "Others"


def log_action(src, dest):
    """Log each file movement for future undo operations."""
    with open(LOG_FILE, "a") as log:
        log.write(f"{datetime.now()} | {src} -> {dest}\n")


def organize_directory(directory):
    """Organize files inside the given directory."""
    if not os.path.exists(directory):
        print("Error: The provided directory does not exist.")
        return

    files = [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]

    if not files:
        print("No files found in this directory.")
        return

    print(f"Organizing {len(files)} files from: {directory}\n")

    for file in tqdm(files, desc="Organizing files"):
        src_path = os.path.join(directory, file)
        category = get_category(file)
        dest_folder = os.path.join(directory, category)
        os.makedirs(dest_folder, exist_ok=True)
        dest_path = os.path.join(dest_folder, file)

        try:
            shutil.move(src_path, dest_path)
            log_action(src_path, dest_path)
        except Exception as e:
            print(f"\nError moving {file}: {e}")

    print("\nOrganization complete.")
    print(f"Log file created: {os.path.abspath(LOG_FILE)}")


def undo_last_organization():
    """Undo the last organization using the log file."""
    if not os.path.exists(LOG_FILE):
        print("No log file found. Nothing to undo.")
        return

    print("Undoing last organization...\n")

    with open(LOG_FILE, "r") as log:
        lines = log.readlines()[::-1]  # Reverse to move files back in correct order

    for entry in tqdm(lines, desc="Restoring files"):
        try:
            _, path_data = entry.split("|")
            src, dest = path_data.strip().split("->")
            src, dest = src.strip(), dest.strip()

            if os.path.exists(dest):
                shutil.move(dest, src)
        except Exception:
            continue

    os.remove(LOG_FILE)
    print("\nUndo complete. All files restored to original locations.")


def main():
    if len(sys.argv) == 1:
        print("\nUsage:")
        print("  python FileSystem_Organizer.py <path_to_directory>")
        print("  python FileSystem_Organizer.py undo\n")
        return

    if sys.argv[1].lower() == "undo":
        undo_last_organization()
    else:
        directory = sys.argv[1]
        organize_directory(directory)


if __name__ == "__main__":
    main()
