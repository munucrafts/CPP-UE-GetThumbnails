import os
import sys
from rembg import remove

# Extract the AssetPath from the command-line arguments
AssetPath = sys.argv[1]

# Generate the output path with the suffix "BgRemoved" before the file extension
output_path = AssetPath[:-4] + "_BgRemoved.png"

# Perform background removal
with open(AssetPath, 'rb') as i:
    with open(output_path, 'wb') as o:
        input_data = i.read()
        output_data = remove(input_data)
        o.write(output_data)

# Extract the filename from the original asset path
original_filename = os.path.basename(AssetPath)

# Delete the original file from the filesystem
os.remove(AssetPath)

# Extract the directory and base filename from the output path
output_dir = os.path.dirname(output_path)
output_filename = os.path.basename(output_path)

# Generate the new output filename without the "_BgRemoved" suffix
new_output_filename = output_filename.replace("_BgRemoved", "")

# Construct the new output path with the updated filename
new_output_path = os.path.join(output_dir, new_output_filename)

# Rename the file
os.rename(output_path, new_output_path)

