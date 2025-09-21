/**
Singleton is a creational design pattern,
which ensures that only one object of its kind exists and provides a single point of access to it for any other code.
**/

/** 
Here’s how it works: imagine that you created an object, but after a while decided to create a new one. 
Instead of receiving a fresh object, you’ll get the one you already created.
**/

/**
Make the default constructor private, to prevent other objects from using the new operator with the Singleton class.
Create a static creation method that acts as a constructor. 
Under the hood, this method calls the private constructor to create an object and saves it in a static field. 
All following calls to this method return the cached object. 
**/