# Sports-Hub Application C++ Back-End

## Project Description

This is a draft pet project for testing Generative AI on different software engineering tasks. It is planned to evolve and grow over time and extend it to other technologies. Specifically, this repo will be a C++ playground with Poco libraries.

The application's legend is based on the sports-hub application description from the following repo: [Sports-Hub](https://github.com/dark-side/sports-hub).

## Available Front-End applications
- [React.js](https://github.com/dark-side/sports_hub_react_skeleton)
- [Angular](https://github.com/dark-side/sports_hub_angular_skeleton)

## Dependencies

- Docker
- Docker Compose

The mentioned dependencies can be installed using the official documentation [here](https://docs.docker.com/compose/install/).
[Podman](https://podman-desktop.io/docs/compose) can be used as an alternative to Docker.

## Setup and Running the Application

### Clone the Repositories

To run the web application with the React front-end, clone the following repositories within the same folder:

```sh
git clone git@github.com:dark-side/sports_hub_cpp_skeleton.git
git clone git@github.com:dark-side/sports_hub_react_skeleton.git
```

### Navigate to the back-end application directory

All commands should be run from the `sports_hub_cpp_skeleton` directory.

### Create .env File

Copy the .env.example file to .env in the root of the project directory:

```sh
cp .env.example .env
```

Update the .env file with your local development credentials and secrets. Make sure not to commit this .env file to version control. 

### Run Docker Compose

Navigate to the back-end application directory and run (`-d` for detached mode to run in the background):

```sh
docker compose up -d
```

### Attach to the Backend Container (optional)

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
