# Instructions to Build, Run, and Test BaseService

## Prerequisites
- CMake version 3.10 or higher
- A C++17 compatible compiler
- Internet connection to fetch Google Test

## Steps to Build
1. Navigate to the `baseService` directory:
   ```bash
   cd /path/to/baseService
   ```
2. Create a build directory and navigate into it:
   ```bash
   mkdir build && cd build
   ```
3. Run CMake to configure the project:
   ```bash
   cmake ..
   ```
4. Build the project:
   ```bash
   make
   ```

## Steps to Run
1. After building, run the executable:
   ```bash
   ./BaseServiceExecutable
   ```

## Steps to Test
1. Run the tests:
   ```bash
   ctest
   ```

## Notes
- Ensure that the `googletest` library is downloaded and built during the CMake configuration step.
- If any issues arise, check the CMake output for errors and ensure all dependencies are installed.
