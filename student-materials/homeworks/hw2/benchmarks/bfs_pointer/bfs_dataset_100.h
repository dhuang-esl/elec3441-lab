#define N 100

Node nodes[N] = {
{
	.id = 0,
	.parent = 0,
	.neighbors = {&nodes[99], &nodes[28], &nodes[51], &nodes[62]}
},
{
	.id = 1,
	.parent = 0,
	.neighbors = {&nodes[80], &nodes[34], &nodes[44], &nodes[14]}
},
{
	.id = 2,
	.parent = 0,
	.neighbors = {&nodes[64], &nodes[68], &nodes[93], &nodes[32]}
},
{
	.id = 3,
	.parent = 0,
	.neighbors = {&nodes[72], &nodes[9], 0, 0}
},
{
	.id = 4,
	.parent = 0,
	.neighbors = {&nodes[82], &nodes[84], &nodes[68], &nodes[5]}
},
{
	.id = 5,
	.parent = 0,
	.neighbors = {&nodes[48], &nodes[4], &nodes[29], 0}
},
{
	.id = 6,
	.parent = 0,
	.neighbors = {&nodes[8], &nodes[89], &nodes[27], &nodes[54]}
},
{
	.id = 7,
	.parent = 0,
	.neighbors = {&nodes[47], &nodes[23], 0, 0}
},
{
	.id = 8,
	.parent = 0,
	.neighbors = {&nodes[6], 0, 0, 0}
},
{
	.id = 9,
	.parent = 0,
	.neighbors = {&nodes[3], &nodes[91], &nodes[62], 0}
},
{
	.id = 10,
	.parent = 0,
	.neighbors = {&nodes[70], &nodes[27], &nodes[45], &nodes[46]}
},
{
	.id = 11,
	.parent = 0,
	.neighbors = {&nodes[63], &nodes[40], &nodes[17], &nodes[22]}
},
{
	.id = 12,
	.parent = 0,
	.neighbors = {&nodes[24], &nodes[58], &nodes[92], &nodes[69]}
},
{
	.id = 13,
	.parent = 0,
	.neighbors = {&nodes[48], &nodes[94], 0, 0}
},
{
	.id = 14,
	.parent = 0,
	.neighbors = {&nodes[87], &nodes[1], &nodes[60], &nodes[62]}
},
{
	.id = 15,
	.parent = 0,
	.neighbors = {&nodes[71], &nodes[49], &nodes[57], &nodes[29]}
},
{
	.id = 16,
	.parent = 0,
	.neighbors = {&nodes[32], &nodes[82], &nodes[20], &nodes[24]}
},
{
	.id = 17,
	.parent = 0,
	.neighbors = {&nodes[57], &nodes[74], &nodes[11], &nodes[28]}
},
{
	.id = 18,
	.parent = 0,
	.neighbors = {&nodes[71], &nodes[42], &nodes[92], &nodes[46]}
},
{
	.id = 19,
	.parent = 0,
	.neighbors = {&nodes[71], &nodes[42], &nodes[93], 0}
},
{
	.id = 20,
	.parent = 0,
	.neighbors = {&nodes[16], &nodes[99], &nodes[52], &nodes[29]}
},
{
	.id = 21,
	.parent = 0,
	.neighbors = {&nodes[80], &nodes[82], &nodes[27], 0}
},
{
	.id = 22,
	.parent = 0,
	.neighbors = {&nodes[72], &nodes[11], &nodes[77], 0}
},
{
	.id = 23,
	.parent = 0,
	.neighbors = {&nodes[7], &nodes[72], 0, 0}
},
{
	.id = 24,
	.parent = 0,
	.neighbors = {&nodes[16], &nodes[90], &nodes[67], &nodes[12]}
},
{
	.id = 25,
	.parent = 0,
	.neighbors = {&nodes[51], &nodes[45], 0, 0}
},
{
	.id = 26,
	.parent = 0,
	.neighbors = {&nodes[99], 0, 0, 0}
},
{
	.id = 27,
	.parent = 0,
	.neighbors = {&nodes[10], &nodes[6], &nodes[45], &nodes[21]}
},
{
	.id = 28,
	.parent = 0,
	.neighbors = {&nodes[37], &nodes[0], &nodes[17], &nodes[85]}
},
{
	.id = 29,
	.parent = 0,
	.neighbors = {&nodes[55], &nodes[15], &nodes[20], &nodes[5]}
},
{
	.id = 30,
	.parent = 0,
	.neighbors = {&nodes[73], &nodes[91], 0, 0}
},
{
	.id = 31,
	.parent = 0,
	.neighbors = {&nodes[42], &nodes[67], &nodes[84], 0}
},
{
	.id = 32,
	.parent = 0,
	.neighbors = {&nodes[2], &nodes[16], &nodes[42], 0}
},
{
	.id = 33,
	.parent = 0,
	.neighbors = {&nodes[41], &nodes[51], &nodes[36], 0}
},
{
	.id = 34,
	.parent = 0,
	.neighbors = {&nodes[40], &nodes[1], &nodes[68], 0}
},
{
	.id = 35,
	.parent = 0,
	.neighbors = {&nodes[38], 0, 0, 0}
},
{
	.id = 36,
	.parent = 0,
	.neighbors = {&nodes[39], &nodes[88], &nodes[33], 0}
},
{
	.id = 37,
	.parent = 0,
	.neighbors = {&nodes[28], 0, 0, 0}
},
{
	.id = 38,
	.parent = 0,
	.neighbors = {&nodes[64], &nodes[35], &nodes[54], 0}
},
{
	.id = 39,
	.parent = 0,
	.neighbors = {&nodes[66], &nodes[36], 0, 0}
},
{
	.id = 40,
	.parent = 0,
	.neighbors = {&nodes[34], &nodes[11], &nodes[76], &nodes[46]}
},
{
	.id = 41,
	.parent = 0,
	.neighbors = {&nodes[71], &nodes[33], &nodes[98], &nodes[89]}
},
{
	.id = 42,
	.parent = 0,
	.neighbors = {&nodes[31], &nodes[32], &nodes[18], &nodes[19]}
},
{
	.id = 43,
	.parent = 0,
	.neighbors = {&nodes[99], &nodes[91], 0, 0}
},
{
	.id = 44,
	.parent = 0,
	.neighbors = {&nodes[1], &nodes[82], &nodes[70], 0}
},
{
	.id = 45,
	.parent = 0,
	.neighbors = {&nodes[25], &nodes[10], &nodes[27], &nodes[92]}
},
{
	.id = 46,
	.parent = 0,
	.neighbors = {&nodes[18], &nodes[40], &nodes[10], &nodes[61]}
},
{
	.id = 47,
	.parent = 0,
	.neighbors = {&nodes[7], &nodes[50], &nodes[84], &nodes[69]}
},
{
	.id = 48,
	.parent = 0,
	.neighbors = {&nodes[5], &nodes[13], 0, 0}
},
{
	.id = 49,
	.parent = 0,
	.neighbors = {&nodes[15], &nodes[98], &nodes[95], &nodes[52]}
},
{
	.id = 50,
	.parent = 0,
	.neighbors = {&nodes[87], &nodes[47], &nodes[68], 0}
},
{
	.id = 51,
	.parent = 0,
	.neighbors = {&nodes[0], &nodes[33], &nodes[25], &nodes[84]}
},
{
	.id = 52,
	.parent = 0,
	.neighbors = {&nodes[79], &nodes[49], &nodes[20], 0}
},
{
	.id = 53,
	.parent = 0,
	.neighbors = {&nodes[65], &nodes[61], &nodes[78], 0}
},
{
	.id = 54,
	.parent = 0,
	.neighbors = {&nodes[80], &nodes[6], &nodes[38], 0}
},
{
	.id = 55,
	.parent = 0,
	.neighbors = {&nodes[97], &nodes[29], 0, 0}
},
{
	.id = 56,
	.parent = 0,
	.neighbors = {&nodes[69], &nodes[58], &nodes[76], &nodes[85]}
},
{
	.id = 57,
	.parent = 0,
	.neighbors = {&nodes[15], &nodes[17], 0, 0}
},
{
	.id = 58,
	.parent = 0,
	.neighbors = {&nodes[56], &nodes[74], &nodes[12], 0}
},
{
	.id = 59,
	.parent = 0,
	.neighbors = {&nodes[64], &nodes[90], 0, 0}
},
{
	.id = 60,
	.parent = 0,
	.neighbors = {&nodes[65], &nodes[73], &nodes[61], &nodes[14]}
},
{
	.id = 61,
	.parent = 0,
	.neighbors = {&nodes[60], &nodes[53], &nodes[46], 0}
},
{
	.id = 62,
	.parent = 0,
	.neighbors = {&nodes[87], &nodes[0], &nodes[9], &nodes[14]}
},
{
	.id = 63,
	.parent = 0,
	.neighbors = {&nodes[81], &nodes[11], &nodes[67], 0}
},
{
	.id = 64,
	.parent = 0,
	.neighbors = {&nodes[73], &nodes[2], &nodes[59], &nodes[38]}
},
{
	.id = 65,
	.parent = 0,
	.neighbors = {&nodes[60], &nodes[53], 0, 0}
},
{
	.id = 66,
	.parent = 0,
	.neighbors = {&nodes[87], &nodes[88], &nodes[39], &nodes[75]}
},
{
	.id = 67,
	.parent = 0,
	.neighbors = {&nodes[63], &nodes[24], &nodes[31], 0}
},
{
	.id = 68,
	.parent = 0,
	.neighbors = {&nodes[34], &nodes[2], &nodes[4], &nodes[50]}
},
{
	.id = 69,
	.parent = 0,
	.neighbors = {&nodes[47], &nodes[56], &nodes[12], &nodes[77]}
},
{
	.id = 70,
	.parent = 0,
	.neighbors = {&nodes[10], &nodes[44], 0, 0}
},
{
	.id = 71,
	.parent = 0,
	.neighbors = {&nodes[15], &nodes[41], &nodes[18], &nodes[19]}
},
{
	.id = 72,
	.parent = 0,
	.neighbors = {&nodes[23], &nodes[3], &nodes[22], 0}
},
{
	.id = 73,
	.parent = 0,
	.neighbors = {&nodes[64], &nodes[60], &nodes[86], &nodes[30]}
},
{
	.id = 74,
	.parent = 0,
	.neighbors = {&nodes[17], &nodes[58], 0, 0}
},
{
	.id = 75,
	.parent = 0,
	.neighbors = {&nodes[66], &nodes[83], 0, 0}
},
{
	.id = 76,
	.parent = 0,
	.neighbors = {&nodes[40], &nodes[98], &nodes[56], 0}
},
{
	.id = 77,
	.parent = 0,
	.neighbors = {&nodes[69], &nodes[22], 0, 0}
},
{
	.id = 78,
	.parent = 0,
	.neighbors = {&nodes[53], &nodes[86], 0, 0}
},
{
	.id = 79,
	.parent = 0,
	.neighbors = {&nodes[52], 0, 0, 0}
},
{
	.id = 80,
	.parent = 0,
	.neighbors = {&nodes[1], &nodes[54], &nodes[85], &nodes[21]}
},
{
	.id = 81,
	.parent = 0,
	.neighbors = {&nodes[63], &nodes[88], 0, 0}
},
{
	.id = 82,
	.parent = 0,
	.neighbors = {&nodes[16], &nodes[44], &nodes[4], &nodes[21]}
},
{
	.id = 83,
	.parent = 0,
	.neighbors = {&nodes[75], 0, 0, 0}
},
{
	.id = 84,
	.parent = 0,
	.neighbors = {&nodes[31], &nodes[47], &nodes[51], &nodes[4]}
},
{
	.id = 85,
	.parent = 0,
	.neighbors = {&nodes[80], &nodes[96], &nodes[28], &nodes[56]}
},
{
	.id = 86,
	.parent = 0,
	.neighbors = {&nodes[73], &nodes[78], 0, 0}
},
{
	.id = 87,
	.parent = 0,
	.neighbors = {&nodes[50], &nodes[66], &nodes[14], &nodes[62]}
},
{
	.id = 88,
	.parent = 0,
	.neighbors = {&nodes[81], &nodes[66], &nodes[36], 0}
},
{
	.id = 89,
	.parent = 0,
	.neighbors = {&nodes[41], &nodes[93], &nodes[6], 0}
},
{
	.id = 90,
	.parent = 0,
	.neighbors = {&nodes[24], &nodes[59], 0, 0}
},
{
	.id = 91,
	.parent = 0,
	.neighbors = {&nodes[9], &nodes[43], &nodes[30], 0}
},
{
	.id = 92,
	.parent = 0,
	.neighbors = {&nodes[18], &nodes[12], &nodes[45], 0}
},
{
	.id = 93,
	.parent = 0,
	.neighbors = {&nodes[89], &nodes[2], &nodes[19], 0}
},
{
	.id = 94,
	.parent = 0,
	.neighbors = {&nodes[13], 0, 0, 0}
},
{
	.id = 95,
	.parent = 0,
	.neighbors = {&nodes[49], 0, 0, 0}
},
{
	.id = 96,
	.parent = 0,
	.neighbors = {&nodes[85], 0, 0, 0}
},
{
	.id = 97,
	.parent = 0,
	.neighbors = {&nodes[55], 0, 0, 0}
},
{
	.id = 98,
	.parent = 0,
	.neighbors = {&nodes[49], &nodes[41], &nodes[76], 0}
},
{
	.id = 99,
	.parent = 0,
	.neighbors = {&nodes[0], &nodes[26], &nodes[43], &nodes[20]}
}
};
