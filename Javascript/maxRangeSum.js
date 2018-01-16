/*
	@author Mark Renzo Santiago
	2018
*/

// Test Case array
const glRange = [7, -3, 1, 4, 21, -18, -2, 4, -1, -6];

const solutionOne = (gainsLosses) => {
	let maxGain = gainsLosses[0];

	// iterate through each index
		// calculate each sub array
			// if currentRange > maxGain
				// maxGain = currentRange
	gainsLosses.forEach((x, i) => {
		let tempSum = x;
		for (let right = i + 1; right < gainsLosses.length; right++) {
			tempSum = tempSum + gainsLosses[right];
			if (tempSum > maxGain) maxGain = tempSum;
		}
	})

	// base case, if no gain (- value total) return 0
	if( maxGain <= 0) return 0;

	return maxGain;
}

/*
	Input
	10 7 -3 -10 4 2 8 -2 4 -5 -6
	Expected Output
	16
*/

// test driver
const s = solutionOne(glRange);
console.log('Max Gain: ' + s);