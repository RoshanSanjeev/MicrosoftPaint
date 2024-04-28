# MicrosoftPaint
OpenGL Paint Application
This project is an OpenGL-based paint application that offers a wide range of drawing and editing tools similar to classic paint programs. Below is a detailed overview of the functionalities implemented in this application:

Features
-Paint Brush Tool: Allows users to create freehand scribbles on the canvas. This tool is ideal for sketching and artistic drawing directly within the application.
-Eraser Tool: Provides the functionality to erase unwanted drawings or mistakes, supporting fine control over the canvas cleaning process.
-Clear Screen Tool: Enables users to clear all contents from the canvas with a single action, resetting the workspace for a new drawing.
-RGB Color Picker: Allows users to select colors using an RGB interface, enabling a vast spectrum of colors for drawing and editing, which enhances the creative possibilities.
-Shape Manipulation
-Shape Tools: Users can draw four different types of shapes: rectangles, circles, triangles, and lines. These tools expand the application's utility for creating structured designs.
-Selector Tool: Facilitates the selection of any shape or scribble by clicking on it. This tool is crucial for editing specific elements within a complex drawing.
-Layer Adjustment: Includes functionalities to bring a selected shape or scribble to the front or send it to the back, allowing users to manage the layering of multiple elements effectively.
-Move and Color Adjustment: Offers the capability to move selected items and change their color, providing comprehensive control over the canvas elements.
Implementation Details
Class Structure: The application leverages a base Shape class from which all drawable shapes and scribbles inherit. This design ensures a consistent and extensible approach to adding new drawable objects.
User Interaction: Designed with an intuitive interface for easy interaction, including tool selection and object manipulation, ensuring a seamless user experience reminiscent of traditional desktop paint applications.
