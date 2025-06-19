Do the following action plan steps to update the project and all code needed.  
If needed, you should ask clarifying questions before you answer or action.  
If decision have an alternative, you should provide a reason for the best choice.  
On each step write tests first, then the code, then run the tests and update the code until tests pass.  

Action plan:  
1. Extend the `baseService` with simple REST API endpoints using an efficient C++ REST API framework.  
2. Modify the `BaseService` class in a way it serves REST API requests. Implement a simple endpoint handler that returns a greeting for testing purposes. Prioritize altering existing source and test files over creating new ones.  
3. Always add logging to any handler added.  
4. Always implement unit tests for any API endpoint.  
5. Ensure the service can be built, run, and tested locally before containerization. If include headers not found issue occurs, ensure the include directories are correctly set in the CMakeLists.txt file with lowercase library names and `_SOURCE_DIR` suffixes.  

After successful completion of this task and in case of discrepancy between the task and the result, you may update the task file with a readjusted instruction prompt that matches all completed steps.  
