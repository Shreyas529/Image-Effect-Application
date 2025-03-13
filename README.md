# Image Effect Application

This repository contains an application for applying various image effects. The application is divided into two main parts: the backend and the frontend.

## Backend

The backend is implemented using Spring Boot and provides RESTful APIs for applying different image effects. The backend code is located in the `ImageEffectBackend` directory.

### Features

* Apply various image effects such as brightness, contrast, flip, Gaussian blur, grayscale, hue-saturation, invert, rotation, sepia, sharpen, and dominant color.
* Logging of applied effects with timestamps.
* Retrieve logs based on effect name or timestamps.
* Clear logs.

### Directory structure

* `ImageEffectBackend/src/main/java/com/iiitb/imageEffectApplication/controller`: Contains the controllers for handling API requests.
  * `ImageEffectBackend/src/main/java/com/iiitb/imageEffectApplication/controller/LogController.java`: Handles requests related to logs.
  * `ImageEffectBackend/src/main/java/com/iiitb/imageEffectApplication/controller/PhotoController.java`: Handles requests related to applying image effects.
* `ImageEffectBackend/src/main/java/com/iiitb/imageEffectApplication/effectImplementations`: Contains the implementations of various image effects.
* `ImageEffectBackend/src/main/java/com/iiitb/imageEffectApplication/libraryInterfaces`: Contains the interfaces for native libraries used for image processing.
* `ImageEffectBackend/src/main/java/com/iiitb/imageEffectApplication/service`: Contains the services for processing image effects and logging.
  * `ImageEffectBackend/src/main/java/com/iiitb/imageEffectApplication/service/LoggingService.java`: Provides methods for logging and retrieving logs.
  * `ImageEffectBackend/src/main/java/com/iiitb/imageEffectApplication/service/PhotoEffectService.java`: Provides methods for applying various image effects.
* `ImageEffectBackend/src/main/resources`: Contains the native libraries for image processing.

### Running the backend

1. Navigate to the `ImageEffectBackend` directory.
2. Run `mvn clean install` to build the project.
3. Run `mvn spring-boot:run` to start the backend server.

## Frontend

The frontend is implemented using Angular and provides a user interface for applying image effects. The frontend code is located in the `ImageEffectFrontend` directory.

### Features

* Upload an image and apply various effects.
* View the applied effects and their parameters.
* View and filter logs of applied effects.

### Directory structure

* `ImageEffectFrontend/src/app`: Contains the Angular components and services.
  * `brightness`: Component for applying brightness effect.
  * `contrast`: Component for applying contrast effect.
  * `dominant-colour`: Component for applying dominant color effect.
  * `flip`: Component for applying flip effect.
  * `gaussian-blur`: Component for applying Gaussian blur effect.
  * `grayscale`: Component for applying grayscale effect.
  * `hue-saturation-effect`: Component for applying hue-saturation effect.
  * `invert`: Component for applying invert effect.
  * `rotation`: Component for applying rotation effect.
  * `sepia`: Component for applying sepia effect.
  * `sharpen`: Component for applying sharpen effect.
  * `_services`: Contains the services for interacting with the backend APIs.
* `README.md`: Contains instructions for setting up and running the frontend.

### Running the frontend

1. Navigate to the `ImageEffectFrontend` directory.
2. Run `npm install` to install the dependencies.
3. Run `ng serve` to start the frontend server.
4. Navigate to `http://localhost:4200/` in your browser to access the application.
