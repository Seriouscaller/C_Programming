
double absoluteValue(double current_term){
    if (current_term < 0){
        return (current_term * -1);
    }else return current_term;
}


unsigned long long int calculateFactorial(int term){
    unsigned long long int factorial = 1;
    while(term-- > 1) factorial *= term;
    return factorial;
    }


long int power(int base, int exponent){
    int product = 1;
    while(exponent-- >= 1) product *= base;
    return product;
}
