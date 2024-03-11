

string change_base(int num, int base) {
    int remainder = 0;
    string res = "";

    while (num > 0) {
        remainder = num % base;
        if (remainder < 10) {
            res = to_string(remainder) + res;
        }
        else {
			char c;
			c = 'A' + (remainder - 10);
            res = c + res;
        }
        num /= base;
    }
    
    return res;
}
