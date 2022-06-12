#ifndef __RFLAGS_H__
#define __RFLAGS_H__

union __rflags_t
{
	unsigned __int64 flags;
	struct
	{
		unsigned __int64 cf : 1;
		unsigned __int64 always_1 : 1;
		unsigned __int64 pf : 1;
		unsigned __int64 reserved_0 : 1;
		unsigned __int64 af : 1;
		unsigned __int64 reserved_1 : 1;
		unsigned __int64 zf : 1;
		unsigned __int64 sf : 1;
		unsigned __int64 tf : 1;
		unsigned __int64 intf : 1;
		unsigned __int64 df : 1;
		unsigned __int64 of : 1;
		unsigned __int64 iopl : 1;
		unsigned __int64 nt : 1;
		unsigned __int64 reserved_2 : 1;
		unsigned __int64 rf : 1;
		unsigned __int64 vf : 1;
		unsigned __int64 ac : 1;
		unsigned __int64 vif : 1;
		unsigned __int64 vip : 1;
		unsigned __int64 idf : 1;
		unsigned __int64 reserved_3 : 9;
	} bits;
};

#endif