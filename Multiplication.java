import java.util.Arrays;

/**
 * Multiplies two binary numbers in the form of strings together with the aid
 * of the binary addition method.
 * Numbers are assumed to be two's complement (signed) binary numbers.
 * The strings do not need to be the same size, but it is assumed they only
 * contain binary numbers.
 *
 * @param: String x: first number as a string, String y: second number as a string
 * @return: String workingSum with the product
 */
public class Multiplication {
        public static String multiply(String x, String y) {
            //match the lengths
            if(x.length() < y.length()) {
                int diff = (y.length()) - x.length();
                x = ((x.substring(0,1).repeat(diff)) + x);
            }
            if(y.length() < x.length()) {
                int diff = (x.length()) - y.length();
                y = ((y.substring(0,1).repeat(diff)) + y);
            }
            // Extend both numbers in order to complete two's complement mult.
            y = (y.substring(0,1).repeat(y.length())) + y;
            x = (x.substring(0,1).repeat(x.length())) + x;
            // Initialize the working answer as 0
            String workingSum = "0";
            //Traverse the array, multiplying the numbers and adding
            for(int i = x.length() - 1; i >= 0; i--) {
                int spacer = 0;
                if(x.charAt(i) == '1') {
                    System.out.println("sum = " + workingSum + "\ny = " + y);
                    workingSum = sumBinary(workingSum, y);
                }
                // For multiplication, shift each consecutive product over
                // one place
                spacer++;
                y = y + "0".repeat(spacer);
            }
            // Trim the length of the product
            if(workingSum.length() > x.length()) {
                int finalLength = workingSum.length() - x.length();
                workingSum = workingSum.substring(finalLength);
            }
            return workingSum;
        }
    /**
     * Method to sum two binary numbers together digit by digit, accounting for
     * carries but not signed figures
     * @param: String x: first number as a string, String y: second number as a string
     * @return: String workingSum with the product
     */
        public static String sumBinary(String sum, String addition) {
            //Match the sizes of the numbers
            if(sum.length() < addition.length()) {
                int diff = addition.length() - sum.length();
                sum = (("0".repeat(diff)) + sum);
            }
            if(addition.length() < sum.length()) {
                int diff = sum.length() - addition.length();
                addition = (("0".repeat(diff)) + addition);
            }
            //Establish the carry as 0 and the working sum as empty
            boolean carry = false;
            //Traverse each string, digit by digit, adding the strings together
            // accounting for the carry
            String workingSum = "";
            for (int i = sum.length() - 1; i >= 0; i--) {
                //If both digits are 1
                if((sum.charAt(i) == '1') && (addition.charAt(i) == '1')) {
                    if (!carry) {
                        workingSum = "0" + workingSum;
                    }
                    else {
                        workingSum = "1" + workingSum;
                    }
                    carry = true;
                    } //If 1 and 1
                // If both digits are 0
                else if((sum.charAt(i) == '0') && (addition.charAt(i) == '0')) {
                    if (!carry) {
                        workingSum = "0" + workingSum;
                    }
                    else {
                        workingSum = "1" + workingSum;
                    }
                    carry = false;
                }// If both 0
                else { //0 and 1
                    if (!carry) {
                        workingSum = "1" + workingSum;
                    }
                    else {
                        workingSum = "0" + workingSum;
                    } // 0 and 1
                }
            }
            // If there is still a carry at the end of the sum, add one to the front
            if (carry) {
               workingSum = "1" + workingSum;
            }
            return workingSum;
        }

}