undefined8 main(void)

{
	long lVar1;
	ulong uVar2;
	undefined1 *puVar3;
	undefined *puVar4;
	ulong uVar5;

	puVar3 = input;
	do {
		puVar4 = puVar3 + 4;
		__isoc99_scanf(&DAT_00102004,puVar3);
		puVar3 = puVar4;
	} while (puVar4 != &_end);
	uVar5 = (ulong)((ulong)input._0_4_ != 0xb) * ((ulong)input._0_4_ + 8);
	uVar2 = (ulong)(uVar5 % 0x1a + 0xe != (ulong)input._4_4_);
	uVar2 = uVar2 * ((ulong)input._4_4_ + 0xd) + uVar5 * (uVar2 * 0x19 + 1);
	uVar5 = (ulong)(uVar2 % 0x1a + 10 != (ulong)input._8_4_);
	uVar2 = uVar5 * ((ulong)input._8_4_ + 2) + uVar2 * (uVar5 * 0x19 + 1);
	uVar5 = (ulong)(uVar2 % 0x1a != (ulong)input._12_4_);
	uVar2 = uVar5 * ((ulong)input._12_4_ + 7) + (uVar2 / 0x1a) * (uVar5 * 0x19 + 1);
	uVar5 = (ulong)(uVar2 % 0x1a + 0xc != (ulong)input._16_4_);
	uVar2 = uVar5 * ((ulong)input._16_4_ + 0xb) + uVar2 * (uVar5 * 0x19 + 1);
	uVar5 = (ulong)(uVar2 % 0x1a + 0xc != (ulong)input._20_4_);
	lVar1 = uVar5 * ((ulong)input._20_4_ + 4) + uVar2 * (uVar5 * 0x19 + 1);
	uVar2 = (ulong)(lVar1 % 0x1a + 0xcU != (ulong)input._24_4_);
	lVar1 = uVar2 * ((ulong)input._24_4_ + 0xd) + (uVar2 * 0x19 + 1) * lVar1;
	uVar2 = (ulong)(lVar1 % 0x1a - 8U != (ulong)input._28_4_);
	lVar1 = uVar2 * ((ulong)input._28_4_ + 0xd) + (uVar2 * 0x19 + 1) * (lVar1 / 0x1a);
	uVar2 = (ulong)(lVar1 % 0x1a - 9U != (ulong)input._32_4_);
	lVar1 = uVar2 * ((ulong)input._32_4_ + 10) + (lVar1 / 0x1a) * (uVar2 * 0x19 + 1);
	uVar2 = (ulong)(lVar1 % 0x1a + 0xbU != (ulong)input._36_4_);
	lVar1 = uVar2 * ((ulong)input._36_4_ + 1) + lVar1 * (uVar2 * 0x19 + 1);
	uVar2 = (ulong)(lVar1 % 0x1a != (ulong)input._40_4_);
	lVar1 = uVar2 * ((ulong)input._40_4_ + 2) + (lVar1 / 0x1a) * (uVar2 * 0x19 + 1);
	uVar2 = (ulong)(lVar1 % 0x1a - 5U != (ulong)input._44_4_);
	lVar1 = uVar2 * ((ulong)input._44_4_ + 0xe) + (uVar2 * 0x19 + 1) * (lVar1 / 0x1a);
	uVar2 = (ulong)(lVar1 % 0x1a - 6U != (ulong)input._48_4_);
	lVar1 = uVar2 * ((ulong)input._48_4_ + 6) + (uVar2 * 0x19 + 1) * (lVar1 / 0x1a);
	uVar2 = (ulong)(lVar1 % 0x1a - 0xcU != (ulong)input._52_4_);
	__printf_chk(1,"z: %ld\n",
			uVar2 * ((ulong)input._52_4_ + 0xe) + (lVar1 / 0x1a) * (uVar2 * 0x19 + 1));
	return 0;
}

