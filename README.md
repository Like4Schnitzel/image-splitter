# image-splitter
An image splitter written in C++ using OpenCV.

### Usage
Whether to scale the split parts to squares may be set to "false" with the second argument. Default is true.

Working directory may be specified as the first argument. Default is current working directory.\
First argument may also be a path to a single file.

If a single file is given the program will only attempt to split that. 
Otherwise the working directory will be walked through (non-recursively) and any existing image files (.png, .jpg, .jpeg or .webp) will be split.
The resulting images are written to a folder with the same name as the image, but with the filename cut off.

### Building
1. Install OpenCV for your operating system. You can find how to do so [here](https://docs.opencv.org/4.x/df/d65/tutorial_table_of_content_introduction.html).
2. Clone the repository by running `git clone https://github.com/Like4Schnitzel/image-splitter/`.
3. Move into the repository with `cd image-splitter`.
4. Edit `src/CMakeLists.txt` and set the path after `OpenCV_DIR` to your OpenCV build directory.
5. From `image-splitter/`, create a new directory named "build". On Linux, you can do this with `mkdir build`.
6. Run `cmake -S ./src/ -B ./build/`.
7. Run `cmake --build ./build/`.

The executable file will be located at `build/ImageSplitter`.
