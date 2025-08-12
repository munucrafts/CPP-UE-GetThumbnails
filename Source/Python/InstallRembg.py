import subprocess
import sys

# Function to install a package
def install_package(package_name):
    try:
        __import__(package_name)
        print(f"'{package_name}' is already installed.")
    except ImportError:
        print(f"'{package_name}' is not installed. Installing now...")
        subprocess.check_call([sys.executable, "-m", "pip", "install", package_name])
        print(f"'{package_name}' has been installed successfully.")

# Install rembg
install_package("rembg")
