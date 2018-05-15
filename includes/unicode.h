#ifndef UNICODE_H
# define UNICODE_H

typedef	struct	s_mask
{
	const unsigned int m1;
	const unsigned int m2;
	const unsigned int m3;
}		t_mask;

const t_mask mask =
{
	.m1 = 49280,
	.m2 = 14712960,
	.m3 = 4034953344,
};
#endif
