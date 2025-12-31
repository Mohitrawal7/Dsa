function rate(password) {
    let score = 0;  
//to rate password strength
    if (!password) {
        return score;
    }   
    // Award points for length if length is greater than or equal to 8 add 10 points
    if (password.length >= 8) {
        score += 10;
    
   
    // Award points based on if a-z and A-Z are present add 15 point  and if 0-9 or characters are present add 10 points
    if (/[a-z]/.test(password) && /[A-Z]/.test(password)) {
        score += 15;
    }   
    if (/\d/.test(password)) {
        score += 10;
    }
}
    // if (/[\W_]/.test(password)) {
    //     score += 10;
    // }

    return score;
}

// Example
console.log(rate("P@ssw0rd123")); // 35
console.log(rate("weak")); // 0
console.log(rate("")); // 0
console.log(rate("StrongPass1")); // 35
console.log(rate("12345678")); // 20
console.log(rate("Aa1")); // 25

