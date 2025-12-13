import os
import sys
from rembg import remove
from onnxruntime import SessionOptions, ExecutionMode, get_available_providers

folder_path = sys.argv[1]

SUPPORTED_EXTENSIONS = (".png", ".jpg", ".jpeg", ".webp")

session_options = SessionOptions()
providers = ["CPUExecutionProvider"] 

def process_images_in_folder(folder):
    if not os.path.isdir(folder):
        print(f"!!! ERROR: The path '{folder}' is not a valid directory.")
        return

    try:
        files = os.listdir(folder)
    except FileNotFoundError:
        print(f"!!! ERROR: Could not find the folder at '{folder}'. Check the path.")
        return
    except PermissionError:
        print(f"!!! ERROR: Permission denied for accessing the folder at '{folder}'.")
        return

    print(f"--- Found {len(files)} items in the folder. ---")

    processed_count = 0

    for filename in files:
        if not filename.lower().endswith(SUPPORTED_EXTENSIONS):
            continue

        if "_BgRemoved.png" in filename:
            continue

        input_path = os.path.join(folder, filename)
        
        base_name = os.path.splitext(filename)[0]
        output_path = os.path.join(
            folder,
            base_name + "_BgRemoved.png"
        )

        print(f"\nProcessing: {filename}")
        
        try:
            with open(input_path, "rb") as f:
                input_data = f.read()

            result_data = remove(
                input_data, 
                session_options=session_options, 
                providers=providers
            )

            with open(output_path, "wb") as f:
                f.write(result_data)

            print(f"   [DONE] Saved successfully to: {output_path}")
            processed_count += 1

        except Exception as e:
            print(f"   [FAIL] FAILED to process {filename}. Error: {e}")
            
    print("\n---")
    print(f"FINAL MESSAGE: Successfully processed {processed_count} files.")
    print("Skipped files that were not supported or already processed.")


if __name__ == "__main__":
    process_images_in_folder(folder_path)