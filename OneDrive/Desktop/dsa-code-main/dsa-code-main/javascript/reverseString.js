// Filename: reverseString.js

// Function to reverse a string
function reverseString(str) {
    // Step 1: Convert string into an array
    // Step 2: Reverse the array
    // Step 3: Join the array back into a string
    return str.split('').reverse().join('');
  }
  
  // Test the function
  const input = "hello";
  const result = reverseString(input);
  
  console.log("Input:", input);
  console.log("Reversed:", result);
  