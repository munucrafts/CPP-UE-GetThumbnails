# Cpp_UE_Get_Thumbnails Plugin

## Description
- The Cpp_UE_Get_Thumbnails plugin is designed for Unreal Engine 5.2 and above. It enables users to save thumbnails of assets in the content browser to .png files by automatically creating a folder named "Thumbnails" in the project directory.
  
  ![Plugin - Save Asset Thumbnails UE](https://github.com/user-attachments/assets/b60133b9-690b-4d40-8299-95b7aa048763)

# There are two steps to follow before using the plugin which are listed below

## Step 01 - Rembg Installation
- Go to "CPP-UE-GetThumbnails\Content\Python" and run "InstallRembg.py".
- Make sure you have Python installed on your system to be able to use the above script.
- Rembg is necessary to remove the background of the extracted thumnail images. If not installed, the extracted thumbnail images will have the default Unreal Engine checkered background.

## Step 02 - Plugin Installation
- Download the latest release from the GitHub repository.
- Unzip the contents of the zip file.
- Remove the "-main" text from the unzipped plugin folder name at the end if its there and if not then leave it as is.
- Go to your Unreal Engine project directory and look for "Plugins" folder. If there is none then make one.
- Copy and paste the unzipped plugin folder into the Plugins folder of your Unreal Engine project.
- If its a "Only Blueprints" project then directly open the project. You will see a pop up asking you if you want to build "CPP-UE-GetThumbnails". Select "Yes" and continue.
- If its a C++ project then follow the same process. If "Build from Source" error is shown then make sure to delete (Saved + Intermediate + .sln file + Binaries), then generate solution from the .uproject file for your project and open the project. If problem still persists then look into your project's C++ code for errors. If still not fixed, then you might have to do some research on your own since its a common problem in Unreal.
- Once the project is open enable the plugin (Plugin Name is "GetThumbnails" inside Unreal Engine) from the Plugins menu if not enabled already.
- Below is a tutorial video for you but I suggest you stick with the README file as its the most updated and contains all the necessary steps in depth.
- Tutorial Video : https://youtu.be/zjpgdz6cLsc

## How to Use?
- Select the assets for which you want to save thumbnails.
- Right-click on the selected assets, look for "Scripted Asset Actions" in the options, and click on "SaveThumbnailsFromAssets".
- Allow it some time to process the images.
- Thumbnails will be saved as .png files in the "Thumbnails" folder located in your project directory.
  
## License
- Feel free to use or modify this plugin according to your requirements. Attribution is appreciated but not required. If you use this plugin in your project, please consider mentioning the author in your project credits or README file.
- If you want to support me then you can make a small contribution through https://buymeacoffee.com/munucrafts as well.
