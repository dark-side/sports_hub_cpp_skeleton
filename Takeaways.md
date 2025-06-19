# Takeaways:  
* The high importance of prompts for achieving desired outcomes. Prompts are "New SQL" to LLMs, so they should be crafted for efficiency.  
* As complexity increases, the results become less appropriate, so we need more prompts and refinements.  
* Handling all becoming a challenging task that requires effective approaches to reduce complexity and increase efficiency:  
    - The need for breaking down tasks into smaller, manageable steps.  
    - Formulating each steps in a way of expected result descriptions, like "Create", "make", "integrate" + expected result.  
    - Forming steps into action plan.  
    Why? As each step needs a context with clarifications and constraints, grouping them into task's action plan forms a enhanced context of the task. However, too big task's action plan can lead to loss of context details. So we need to bound tasks properly.  
    - Having a defined action plan for a task we can add rules for Agent to follow on each step, like "Clarify before proceeding if needed", "Suggest better alternative", "Ensure all tests are passing", "After successful completion, readjust initial instructions to match the results", etc. So we iteratively test and refine the action plan.  
    - It comes to templates for tasks, having a goal, rules to follow, and action plan steps, with request to analyze result and readjust initial prompts at the end.  
    - Here we see the value of structured requests. And we can use a proper format like Outline or Markdown to enhance this. Furthermore, we can refer to it's sections for clarifications if needed.  
    - Having such well-structured tasks, we don't need a complicated prompt to start execution, we can just say "Follow instructions in the TaskX.md file step by step." And move to the next task after successful completion.  
    - But what if it fails? Well, we have already given rules to avoid failure, but it's possible that Agent gives up after a few attempts. Those cases are probably untypical and Copilot usually suggests to read the documentation.  
    - Here some tips to resolve failures:  
        - The simpliest way is to just try another model with all the same inputs.  
        - We can switch to the Ask mode and ask clarifying questions to understand what went wrong or take a suggestion to RTFM.  
        - After clarifying the issue, we can modify our task file with some particular adjustments. But the tricky part is that reajusment could break what was previously working or even be ignored.  
        - The great option to just adjust the starting prompt, like "Follow instructions in the TaskX.md file step by step. If you fail, try to replace 'problematic part' with 'solution'".  
        - Or put fix instructions into dedicated task patch file.  
        In any case, our structured approach allows us to make precise adjustments.  
    - In the same way we can try different parameters to our requests, like "Follow instructions in the TaskX.md file step by step. Try to use 'Library' for 'specific functionality/step'".  

## Pros:  
- We have produced a lot of info for Copilot, applied some efforts to make it work smoothly step by step. And the great thing that those all are valuable artifacts.  
- Also Copilot helps to autocomplete text meaningfully while writing tasks so it wasn't too dramatically hard.  
- It turned into clear instructions and documentation for the project in "Explain me like I'm five" style.  
- We have history of changes, where problems were highlighted and resolved with patches.  
- We can reuse all as templates for similar tasks with slight adjustments and no extra efforts.  

## Cons:  
- It's not a formalized process, we can't make Copilot to follow our instructions strictly, so we need to experiment and iterate a lot.  
- It's not a deterministic process, so we need some luck to get the same desired results.  
- Be aware that Copilot modifies sources and also undoes changes when you delete chat requests.  
- Also it's not always easy to handle dependencies and integration issues, but it's also true for manual C++ development.  
- Copilot may not properly interpret results of commands it executes in terminal: for example, it may run `ls -la ${library_SOURCE_DIR}` to inspect the library sources, but doesn't recognize the problem that this variable is not defined and it looking at current directory files. We need to carefully watch all steps it takes.  
