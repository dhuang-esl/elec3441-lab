#define N 10

Node nodes[N] = {
{
	.id = 0,
	.parent = 0,
	.neighbors = {&nodes[7], &nodes[1], &nodes[2], &nodes[3]}
},
{
	.id = 1,
	.parent = 0,
	.neighbors = {&nodes[0], &nodes[9], 0, 0}
},
{
	.id = 2,
	.parent = 0,
	.neighbors = {&nodes[7], &nodes[0], &nodes[9], &nodes[5]}
},
{
	.id = 3,
	.parent = 0,
	.neighbors = {&nodes[7], &nodes[0], &nodes[9], 0}
},
{
	.id = 4,
	.parent = 0,
	.neighbors = {&nodes[5], &nodes[6], 0, 0}
},
{
	.id = 5,
	.parent = 0,
	.neighbors = {&nodes[8], &nodes[2], &nodes[4], 0}
},
{
	.id = 6,
	.parent = 0,
	.neighbors = {&nodes[7], &nodes[8], &nodes[4], 0}
},
{
	.id = 7,
	.parent = 0,
	.neighbors = {&nodes[0], &nodes[2], &nodes[3], &nodes[6]}
},
{
	.id = 8,
	.parent = 0,
	.neighbors = {&nodes[5], &nodes[6], 0, 0}
},
{
	.id = 9,
	.parent = 0,
	.neighbors = {&nodes[1], &nodes[2], &nodes[3], 0}
}
};
