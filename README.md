# C++ Back-End and Auth services
 
## Project Description

TODO

## Available Front-End applications
- [React.js](https://github.com/rtriska/reactjs_fe_genai_plgrnd)

## Dependencies

- Docker
- Docker Compose

The mentioned dependencies can be installed using the official documentation [here](https://docs.docker.com/compose/install/).

## Setup and Running the Application

### Create .env File

Copy the .env.example file to .env in the root of the project directory:

```sh
cp .env.example .env
```
Update the .env file with your local development credentials and secrets. Make sure not to commit this .env file to version control. 

### Clone the Repositories

To run the web application with the React front-end, clone the following repositories within the same folder:

```sh
git clone git@github.com:rtriska/cpp_app_plgrnd.git
git clone git@github.com:rtriska/reactjs_fe_genai_plgrnd.git
```

### Run Docker Compose

Navigate to the back-end application directory and run:

```sh
docker compose up
```

### Attach to the Backend Container

Run `docker ps` and copy the `backend` application container ID. Then, connect to the container with the following command:

```sh
docker exec -ti <CONTAINER ID> /bin/bash
```

### Accessing the Application
To access the application in a browser locally, open the following URL:
- Mac, Linux - `http://localhost:3000/`
- Windows - `http://127.0.0.1:3000/`

## License

Licensed under either of

- [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0)
- [MIT license](http://opensource.org/licenses/MIT)

Just to let you know, at your option.

## Contribution
Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in your work, as defined in the Apache-2.0 license, shall be dual licensed as above, without any additional terms or conditions.

**Should you have any suggestions, please create an Issue for this repository**
