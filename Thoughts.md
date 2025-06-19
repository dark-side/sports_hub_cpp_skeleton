# General thoughts:  
Just a rationale of what C++ specific solution could be and any possible alternatives.  
It's a Client-Server application so we can balance between how powerful client and server should be.  
The options are:  
1. Thin client (Web page, PWA, embedded browser) and fully featured back-end.  
2. Rich client with fully functional core and UI and simplified back-end for synchronization (could be serverless).  
3. Implement both.  

## Pros/cons:  
- Thin client and fully featured back-end:  
  - Pros:  
    - Fully centralized  
    - Easy to deploy and update  
    - Can be accessed from any device with a browser  
    - Installation is not required  
    - Shorter marketing funnel, easier to try  
  - Cons:  
    - Requires advanced front-end frameworks  
    - Requires internet connection, limited offline functionality  
    - Lower performance compared to a rich client  
    - Limited access to device features  
    - Higher operational costs for back-end infrastructure  
- Rich client and simplified back-end:  
  - Pros:  
    - High performance  
    - Offline mode with synchronization on-demand  
    - Full access to device  
    - Higher security and privacy  
    - Can be cross-platform or native  
    - Better user experience  
    - Easier to monetize, smooth payment integration  
    - Naturally scalable  
    - Simplified back-end, can be serverless  
    - Reduced operational costs  
  - Cons:  
    - More complex development  
    - Needs to be deployed and updated  
    - Some minimal requirements to the client device  
    - Additional steps in marketing funnel  

## Implementation thoughts:  
- In the case of Thin client, WebUI is the only one choice  
- In the case of Rich client, UI can be implemented as a WebUI, or as a native application  
  - Core functionality as library and executable upon it, either as native application or as local server  
- For delivering web context a Web server is obviously needed  
- Back-end requires computational resources and storage.  
  - It's a RESTful API service  
  - Can be implemented as a monolithic service or as a set of microservices or serverless functions  
  - Computational options:  
    - VPS  
    - Kubernetes pod  
    - Serverless function  
  - DB storage options:  
    - SQL  
    - NoSQL  
    - Hybrid  
  - Persistent file storage  

## Key points from the functional and non-functional requirements:  
- cloud-based, but cloud agnostic  
- scalable, multi-region  
- HTTPS only  
- RESTful API  
- structured data  
- 1000 simultaneous requests  
- time to start is < 2 seconds  
- response time is < 3 seconds (max 10s)  
- SLA 95%  
- 365 days of logs storing  

## Requirements fit:  
* All cloud providers support the required features with desired SLA and multi-AZ support.  
* We should pay attention to the time to start (cold start) as it is a key point for serverless functions.  Should check PoC for specific configuration. If time to start is more than 2 seconds, we should consider using an always-on VPS or Kubernetes pod with High-Availability mechanisms with synchronization between active and standby instances if needed, or some warm-up mechanism for serverless services.  
* PoC should check how many requests can be handled by a single instance. So we can be aware of how many instances we need.  
* According to notes above, PoC should be highly optimized for CPU intensive usage.  
* We should pay attention to auto-scaling time as it is a key point for fitting the requirements of 1000 simultaneous requests and response time.  
* To improve response time, we should consider using:  
  * Optimizing the code and database queries to reduce processing time  
  * Asynchronous processing of requests using a message queue  
  * Caching for faster data retrieval  
  * Better database indexing for faster queries  
  * CDN for static content delivery  
* Use a load balancer to distribute requests between instances  
* Have monitoring and logging  
* Strategy of moving logs to cold storage  

## Conclusion:  
It's reasonable to start with a web client and a fully featured back-end.  
The project core functionality can be implemented as a monolithic service with a single database. According to non-functional requirements monolith should be fast and tiny, but we should keep it internally modular for further splitting to microservices in case of growing scale and complexity.  
Additional features can be implemented as microservices or serverless functions.  

Alternative approach is either too wide, like rich web client with local server communicating to cloud services, or too specific, like to create a native client application with a client API of cloud services  integrated (like GCP Firestore).  

Composing core functionality as a set of libraries allows us to variate any approaches.  

The proposed in documentation architecture for this project is relevant.  
