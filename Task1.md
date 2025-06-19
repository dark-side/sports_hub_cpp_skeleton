Do the following action plan steps to create project and all code needed.  
If needed, you should ask clarifying questions before you answer or action.  
If decision have an alternative, you should provide a reason for the best choice.  
On each step write tests first, then the code, then run the tests and update the code until tests pass.  

Action plan:  
1. Create folder named `services` in the root of the repository.  
2. In `services` create a `baseService` subdirectory for a specific service having `include/`, `src/` and `tests/` subdirectories inside it.  
3. Create a C++ 17 CMake project that builds a static library and an executable. Add Google Test to the project.  
4. Place files of library sources, headers and tests, plus `main.cpp` for the executable in the corresponding directories.
5. Create a simple class `BaseService` in the library that has a method `start()` and `stop()`, which logs messages to the console. The executable should create an instance of this class and call these methods.  
6. Write unit tests for the library. Ensure that the unit tests pass successfully.  
7. Create a `.gitignore` file in the root of the repository to ignore build artifacts and other commonly uncommitted files according to the project type and structure.  
8. Write detailed instructions on how to build, run and test the service in the `baseService/docs/instructions.md` file.  

After successful completion of this task and in case of discrepancy between the task and the result, you may update the task file with a readjusted instruction prompt that matches all completed steps.  
