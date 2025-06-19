# SportsHubCpp

## Thoughts  
Optional [preliminary thoughts](Thoughts.md) on the project implementation.  

## Goal  
The goal is to create a ready to deploy REST service template that can be used as a foundation for specific services with additional endpoints and functionality clarified by further prompts.  

## Action plan steps  
Select the Agent mode and GPT-4o model in the Copilot Chat, then:  
1. [Ask](Task1.md) Copilot to create the project step by step by the following prompt:  
```plaintext
Follow instructions in the Task1.md file step by step.
```
2. Optionally you can switch to the Ask mode for suggesting proper C++ REST library:  
```plaintext
What C++ REST server library you suggest to integrate to the project?
```
It recommends a lot with reasonable justification so it's easy to choose the right one.  
In our case its crucial to have HTTPS support and efficiency, so we can choose between Microsoft CppRestSDK, uWebSockets, Drogon, wfrest.  
We can try any library by placing it in tuned prompt like "Follow instructions in the Task2.md file step by step. Use 'Library'."  

So switch back to the Agent mode and [Ask](Task2.md) Copilot to add simple and effective uWebSockets library to the project by the following prompt that takes into account it's specific with cmake project integration:  
```plaintext
Follow instructions in the Task2.md file step by step. Use uWebSockets header-only C++ library and its dependency uSockets library, both integrated to the project's CMakeLists.txt as in this example https://github.com/tony-go/cmake-uwebsockets/blob/main/CMakeLists.txt. Built custom static library with flag 'WITH_OPENSSL=1' to link it with the project.
```
3. [Ask](Task3.md) Copilot to to containerize the service by the following prompt:  
```plaintext
Follow instructions in the Task3.md file step by step.
```
4. [Ask](Task4.md) Copilot to add web server functionality by the following prompt:  
```plaintext
Follow instructions in the Task4.md file step by step.
```
5. [Ask](Task5.md) Copilot to set up CI/CD pipeline by the following prompt:  
```plaintext
Follow instructions in the Task5.md file step by step.
```

## Results  
Expected project structure:  
```plaintext
SportsHubCpp/
├── services/ 
│   └── baseService/
│       ├── docs/
│       │   └── instructions.md
│       ├── include/
│       │   └── BaseService.h
│       ├── src/
│       │   ├── BaseService.cpp
│       │   └── main.cpp
│       ├── tests/
│       │   └── BaseServiceTest.cpp
│       └── CMakeLists.txt
├── CMakeLists.txt
└── README.md
```

## Conclusion  
It's possible to guide the Copilot in Agent mode to create project without coding. But as process is not formalized, it requires experimentation and adjusted approaches to achieve the desired results.  
More details in [Takeaways.md](Takeaways.md).  
