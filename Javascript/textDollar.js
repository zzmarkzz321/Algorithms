/*
	@author Mark Renzo Santiago
	2018
*/

const valueMap = {
	3: 'Hundred',
	4: 'Thousand',
	7: 'Million',
	10: 'Billion'
}

const DOLLARS = 'Dollars';

const tensMap = {
	9: 'Ninety',
	8: 'Eighty',
	7: 'Seventy',
	6: 'Sixty',
	5: 'Fifty',
	4: 'Forty',
	3: 'Thirty',
	2: 'Twenty',
	1: 'Ten',
	0: ''
}

const specialTens = {
	9: 'Nineteen',
	8: 'Eighteen',
	7: 'Seventeen',
	6: 'Sixteen',
	5: 'Fifteen',
	4: 'Fourteen',
	3: 'Thirteen',
	2: 'Twelve',
	1: 'Eleven',
}

const numMap = {
	9:  'Nine',
	8:  'Eight',
	7:  'Seven',
	6:  'Six',
	5:  'Five',
	4:  'Four',
	3:  'Three',
	2:  'Two',
	1:  'One',
	0:  ''
}

/*
	Example: 
	1 = one
	21 = twenty-one
	221 = two-hundred-twenty-one
	2221 = two-thousand-two-hundred-one-hundred
	21000 = twenty-one-thousand
	21100 = twenty-one-thousand-one-hundred
*/

// edge cases
// unique naming for numbers 11 - 19: eleven, twelve, etc

const solution = input => {
	// switch based on length of array
	// length 1 is in ones place, 2 is in tens, 3 is in hundreds, etc

	let i = String(input).split('').map(Number);
	let output = '';
	let digits = i.length;
	let digit = 0;

	switch (digits) {
		case 10:
			output = output.concat(numMap[i[digit]], valueMap[10]);
			digit = digit + 1;
		case 9:
			output = output.concat(numMap[i[digit]], valueMap[3]);
			digit = digit + 1;
		case 8:
			output = output.concat(tensMap[i[digit]]);
			digit = digit + 1;
		case 7:
			output = output.concat(numMap[i[digit]], valueMap[7]);
			digit = digit + 1;
		case 6:
			output = output.concat(numMap[i[digit]], valueMap[3]);
			digit = digit + 1;
		case 5:
			output = output.concat(tensMap[i[digit]]);
			digit = digit + 1;
		case 4:
			output = output.concat(numMap[i[digit]], valueMap[4]);
			digit = digit + 1;
		case 3:
			output = output.concat(numMap[i[digit]], valueMap[3]);
			digit = digit + 1;
		case 2:
			output = output.concat(tensMap[i[digit]]);
			digit = digit + 1;
		case 1: 
			output = output.concat(numMap[i[digit]]);
			break;
		default:
			console.log('Input a number 0 <= n <= 9,999,999,999');
			break;
	}

	return output.concat(DOLLARS);
}

// Test Driver
const s = solution(9999999999);
console.log('Solution: ' + s);