class Solution {
public:
    bool validUtf8(vector<int>& data) {
int remainingnumberOfBytesToProcess = 0;

    for (int num : data) {
        if (remainingnumberOfBytesToProcess == 0) {
            // Check the number of numberOfBytesToProcess for the current character
            if ((num >> 7) == 0b0) {
                // 1-byte character
                remainingnumberOfBytesToProcess = 0;
            } else if ((num >> 5) == 0b110) {
                // 2-byte character
                remainingnumberOfBytesToProcess = 1;
            } else if ((num >> 4) == 0b1110) {
                // 3-byte character
                remainingnumberOfBytesToProcess = 2;
            } else if ((num >> 3) == 0b11110) {
                // 4-byte character
                remainingnumberOfBytesToProcess = 3;
            } else {
                return false; // Invalid start of a character
            }
        } else {
            // Check if the current byte is of the form 10xxxxxx
            if ((num >> 6) != 0b10) {
                return false; // Invalid continuation byte
            }
            remainingnumberOfBytesToProcess--;
        }
    }

    return remainingnumberOfBytesToProcess == 0; // Check if all characters have been fully read

    }
};