#ifndef __DR_H__
#define __DR_H__

union __drx_t
{
	unsigned __int64 breakpoint_linear_address;
	void* breakpoint_address;
};

union __dr6_t
{
	unsigned __int64 flags;
	struct
	{
		unsigned __int64 B0 : 1;
		unsigned __int64 B1 : 1;
		unsigned __int64 B2 : 1;
		unsigned __int64 B3 : 1;
		unsigned __int64 always_1 : 8;
		unsigned __int64 always_0 : 1;
		unsigned __int64 BD : 1;
		unsigned __int64 BS : 1;
		unsigned __int64 BT : 1;
		unsigned __int64 RTM : 1;
	};
};

union __dr7_t
{
	unsigned __int64 flags;
	struct
	{
		unsigned __int64 L0 : 1;
		unsigned __int64 G0 : 1;
		unsigned __int64 L1 : 1;
		unsigned __int64 G1 : 1;
		unsigned __int64 L2 : 1;
		unsigned __int64 G2 : 1;
		unsigned __int64 L3 : 1;
		unsigned __int64 G3 : 1;
		unsigned __int64 LE : 1;
		unsigned __int64 GE : 1;
		unsigned __int64 always_1 : 1;
		unsigned __int64 RTM : 1;
		unsigned __int64 always_0 : 1;
		unsigned __int64 GD : 1;
		unsigned __int64 reserved_0 : 2;
		unsigned __int64 RW0 : 2;
		unsigned __int64 LEN0 : 2;
		unsigned __int64 RW1 : 2;
		unsigned __int64 LEN1 : 2;
		unsigned __int64 RW2 : 2;
		unsigned __int64 LEN2 : 2;
		unsigned __int64 RW3 : 2;
		unsigned __int64 LEN3 : 2;
		unsigned __int64 reserved_1 : 32;
	} bits;
};

#endif