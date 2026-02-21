# Cpp-UE-Get-Thumbnails Plugin

---

## Description

- The **Cpp-UE-Get-Thumbnails** plugin is designed for **Unreal Engine 5.3 and above**.  
- It enables users to save thumbnails of assets in the **Content Browser** to **.png files** by automatically creating a folder named **"Thumbnails"** in the project directory.

<p align="center">
  <img src="https://github.com/user-attachments/assets/b60133b9-690b-4d40-8299-95b7aa048763" alt="Plugin - Save Asset Thumbnails UE" />
</p>

---

## There are two steps to follow before using the plugin

---

### Step 01 - Rembg Installation

- Go to:

  ```
  CPP-UE-GetThumbnails\Source\Python
  ```

- Run:

  ```
  InstallRembg.py
  ```

- Ensure you have **Python** installed on your system to be able to use the above script.
- **Rembg** is necessary to remove the background of the extracted thumbnail images.
- If not installed, the extracted thumbnail images will have the default **Unreal Engine checkered background**.

---

### Step 02 - Plugin Installation

- Download the **latest release** from the GitHub repository.
- Unzip the contents of the zip file.
- Remove the **"-main"** text from the unzipped plugin folder name at the end if it's there, and if not, then leave it as is.
- Go to your **Unreal Engine project directory** and look for the **"Plugins"** folder. If there is none, then make one.
- Copy and paste the unzipped plugin folder into the **Plugins** folder of your Unreal Engine project.
- Build and open the project.
- Once the project is open, enable the plugin  
  (Plugin Name is **"GetThumbnails"** inside Unreal Engine)  
  from the **Plugins menu** if not already enabled.
- Below is a tutorial video for you, but I suggest you stick with the README file, as it's the most up-to-date and contains all the necessary steps in depth.

**Tutorial Video:**  
https://youtu.be/zjpgdz6cLsc

---

## How to Use?

- Select the assets for which you want to save thumbnails.
- Right-click on the selected assets.
- Look for **"Scripted Asset Actions"** in the options.
- Click on **"SaveThumbnailsFromAssets"**.
- Allow it some time to process the images.
- Thumbnails will be saved as **.png files** in the **"Thumbnails"** folder located in your project directory.

---

## License

- Feel free to use or modify this plugin according to your requirements.
- Attribution is appreciated but not required.
- If you use this plugin in your project, please consider mentioning the author in your project credits or README file.
