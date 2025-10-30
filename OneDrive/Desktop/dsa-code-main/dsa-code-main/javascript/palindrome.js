/*
    Implement a function in JavaScript that checks whether a given string is a palindrome (reads the same backward and forward). 
    The function should ignore case sensitivity and non-alphanumeric characters.

 */

function isPalindrome(str) {
  str = str.toLowerCase().replace(/[^a-z0-9]/g, "");
  let left = 0, right = str.length - 1;

  while (left < right) {
    if (str[left] !== str[right]) return false;
    left++;
    right--;
  }
  return true;
}

console.log(isPalindrome("level")); // true
console.log(isPalindrome("world")); // false

