<?php


// Input string or number
$input = "madam"; 

// Reverse the string
$reversed = strrev($input);

// Check if palindrome
if ($input === $reversed) {
    echo "$input is a palindrome.";
} else {
    echo "$input is not a palindrome.";
}
?>
