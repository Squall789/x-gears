////////////////////////////////
// 0x0B_EntityNPCInit
current_entity_id = w[800af1f0];
V0 = w[800aefe4];
A0 = hu[V0 + current_entity_id * 64 + 58];
A0 = A0 & f07f;
A0 = A0 | 0200;
[V0 + current_entity_id * 64 + 58] = h(A0);

A0 = 1;
read_two_bytes_with_80;

A0 = current_entity_id;
A1 = V0;
address_2dsprite = w[800aeff0];
A2 = address_2dsprite + w[address_2dsprite + V0 * 4 + 4];
A3 = 0;
A4 = 0;
A5 = V0 | 80;
A6 = 0;
func76150;

funca0224;

// move script pointer
A0 = w[800af54c];
[A0 + cc] = h(hu[A0 + cc] + 3);

V1 = w[A0];
V1 = V1 | 00000100;
V1 = V1 & ffffff7f; // make solid
[A0] = w(V1);

[A0 + 4] = w(w[A0 + 4] & fffff7ff);

V1 = w[800af1f0];
V0 = w[800aefe4];
[V0 + V1 * 5c + 58] = h(hu[V0 + V1 * 5c + 58] & ffdf);
////////////////////////////////



////////////////////////////////
// 0x16_EntityPCInit
A0 = 1;
read_two_bytes_with_80;
A0 = V0;
convert_magic_to_pc_id;
character_id = V0;

A0 = character_id;
get_party_slot_id;
S0 = V0;

struct = w[800af54c]
[struct + e4] = h(character_id);



current_entity_id = w[800af1f0];
struct_small = w[800aefe4];
V1 = hu[struct_small + current_entity_id * 5c + 58];
V1 = V1 & f07f;
V1 = V1 | 0200;
[struct_small + V1 * 5c + 58] = h(V1);



// if character in party
if (S0 != -1)
{
    // if in 1st slot (leader)
    if (S0 == 0)
    {
        [800b1740] = w(current_entity_id);
        [800b1812] = h(current_entity_id);

        V0 = w[struct + 0];
        V0 = V0 | 00004400;
        V0 = V0 & ffffff7f; // set solid
        [struct + 0] = w(V0);
    }

    [80059ad4 + S0 * 4] = w(current_entity_id);

    T1 = w[800a173c];
    if (T1 != 0)
    {
        A0 = current_entity_id;
        model_id = bu[800ad76c + character_id];
        A1 = model_id + T1;
        address = w[800aeff0];
        A2 = address + w[address + model_id * 4 + T1 * 4 + 4];
        A3 = 0;
        A4 = 0;
        A5 = (model_id + T1) | 80;
        A6 = 1;
        func76150;

        V0 = w[struct + 0];
        V0 = V0 | 00000400;
        V0 = V0 & fffffcff;
        [struct + 0] = w(V0);

        V1 = w[80059a38];
        if (bu[V1 + S0 + 22b1] != 0)
        {
            A0 = w[8006f020 + S0 * 4];
            x = w[struct_small + A0 * 5c + 4];
            y = w[struct_small + current_entity_id * 5c + 4]
            [struct_small + current_entity_id * 5c + 0] = w(x);
            [struct_small + A0 * 5c + 4] = w(y);
            x = w[struct + 0];
            x = x | 00000200;
            x = x & fffffaff;
            [struct_small + A0 * 5c + 0] = w(x);
        }
    }
    else
    {
        A0 = current_entity_id;
        A1 = S0;
        A2 = w[80059aa4 + S0 * 4];
        A3 = 1;
        A4 = 0;
        A5 = A1;
        A6 = 1;
        func76150;

        V0 = w[struct + 0];
        V0 = V0 | 00000400;
        V0 = V0 & fffffcff;
        [struct + 0] = w(V0);
    }

    [800af1f4] = h(ff40);

    [struct_small + current_entity_id * 5c + 58] = h(hu[struct_small + current_entity_id * 5c + 58] & ffdf);

    A0 = 2;
    get_bytes_from_800C2F3C;

    A0 = V0;
    func9efe4;

    funca0224;

    [struct + 4] = w([struct + 4] & fffff7ff);
}
else
{
    A0 = current_entity_id;
    A1 = 0;
    A2 = w[80059aa4];
    A3 = 1;
    A4 = 0;
    A5 = 0;
    A6 = 1;
    func76150;

    [struct + 0] = w(w[struct + 0] | 00000001);
    [struct + 4] = w(w[struct + 4] | 00100000);

    [800af4c0] = w(S0);
    [800af594] = w(S0)
}

[struct + 0] = w(w[struct + 0] | 00020000);
[struct + 4] = w(w[struct + 4] | 00000400);

[struct + cc] = h(hu[struct + cc] + 3);
////////////////////////////////



////////////////////////////////
// 0xBC_EntityNoModelInit
// funca02cc
A0 = w[800af1f0];
A1 = 0;
address = w[800aeff0];
A2 = address + w[address + 4];
A3 = 0;
A4 = 0;
A5 = 80;
A6 = 1;
func76150;

funca0224;

// move script pointer
A0 = w[800af54c];
[A0 + cc] = h(hu[A0 + cc] + 1);

[A0 + 0] = w(w[A0 + 0] | 00000100);
[A0 + 4] = w(w[A0 + 4] | 00000800);
////////////////////////////////



////////////////////////////////
// func76150
S6 = A4; // [SP + 10] = w(0);
S3 = A0; // currently entity id
S1 = A1; // model id to load (local most likely)
S4 = A2; // offset to data in 2dsprite block to load
S7 = A3; // 0
S0 = A5; // [SP + 14] = w(80);
FP = A6; // [SP + 18] = w(1); in case of model == 0

A0 = 8;
A1 = 0;
func322bc;

S2 = S3 * 5c;
V1 = w[800aefe4];
V1 = V1 + S2;
struct = w[V1 + 4c];
[struct + 126] = b(S0);
[struct + 127] = b(S1);
[struct + 130] = w((w[struct + 130] & cfffffff) | ((S7 & 3) << 1c));
[struct + 134] = w((w[struct + 134] & fffffff0) | (S6 & f));
[struct + 134] = w((w[struct + 134] & ffffffef) | ((FP & 1) << 4));

if( S7 == 0 )
{
    S5 = hu[800b144c + S1 * 8]; // tx
    S0 = hu[800b144e + S1 * 8]; // ty
    if( S6 == 0 )
    {
        V1 = w[800aefe4] + S2;
        if( hu[V1 + 5a] & 1 )
        {
            A0 = w[V1 + 4];
            func22f24;
        }

        A0 = S4;
        A1 = 100;      // clut x
        A2 = S1 + 1e0; // clut y
        A3 = S5;       // tx
        A4 = S0;       // ty
        A5 = 40;
        func24330; // sprite set up
    }
    else
    {
        80076318	lui    v0, $800b
        8007631C	lw     v0, $efe4(v0)
        80076320	nop
        80076324	addu   v1, s2, v0
        80076328	lhu    v0, $005a(v1)
        8007632C	nop
        80076330	andi   v0, v0, $0001
        80076334	beq    v0, zero, L7634c [$8007634c]
        80076338	addu   a0, s4, zero
        8007633C	lw     a0, $0004(v1)
        80076340	jal    func22f24 [$80022f24]
        80076344	nop
        80076348	addu   a0, s4, zero

        L7634c:	; 8007634C
        8007634C	sll    a1, s6, $04
        80076350	addiu  a1, a1, $0100
        80076354	sll    a1, a1, $10
        80076358	sra    a1, a1, $10
        8007635C	addiu  a2, s1, $01e0
        80076360	sll    a2, a2, $10
        80076364	sra    a2, a2, $10
        80076368	sll    a3, s5, $10
        8007636C	sra    a3, a3, $10
        80076370	sll    v0, s0, $10
        80076374	sra    v0, v0, $10
        80076378	sw     v0, $0010(sp)
        8007637C	ori    v0, zero, $0040
        80076380	sw     v0, $0014(sp)
        80076384	jal    func240a0 [$800240a0]
        80076388	sw     s6, $0018(sp)
    }

    8007638C	lui    v1, $800b
    80076390	lw     v1, $efe4(v1)
    80076394	addu   s0, v0, zero
    80076398	addu   v1, s2, v1
    800763A0	sw     s0, $0004(v1)
}
else
{
    800763A4	lui    v0, $800b
    800763A8	lw     v0, $efe4(v0)
    800763AC	nop
    800763B0	addu   v1, s2, v0
    800763B4	lhu    v0, $005a(v1)
    800763B8	nop
    800763BC	andi   v0, v0, $0001
    800763C0	beq    v0, zero, L763d8 [$800763d8]
    800763C4	ori    v0, zero, $0001
    800763C8	lw     a0, $0004(v1)
    800763CC	jal    func22f24 [$80022f24]
    800763D0	nop
    800763D4	ori    v0, zero, $0001

    L763d8:	; 800763D8
    800763D8	bne    s7, v0, L76400 [$80076400]
    800763DC	sll    v0, s1, $06
    800763E0	addiu  s0, v0, $0100
    800763E4	addu   a0, s4, zero
    800763E8	ori    a1, zero, $0100
    800763EC	addiu  a2, s1, $00e0
    800763F0	sll    a2, a2, $10
    800763F4	sra    a2, a2, $10
    800763F8	j      L7641c [$8007641c]
    800763FC	ori    a3, zero, $0280

    L76400:	; 80076400
    80076400	addiu  s0, v0, $0100
    80076404	addu   a0, s4, zero
    80076408	ori    a1, zero, $0100
    8007640C	addiu  a2, s1, $00e3
    80076410	sll    a2, a2, $10
    80076414	sra    a2, a2, $10
    80076418	ori    a3, zero, $02a0

    L7641c:	; 8007641C
    8007641C	sll    v0, s0, $10
    80076420	sra    v0, v0, $10
    80076424	sw     v0, $0010(sp)
    80076428	ori    v0, zero, $0008
    8007642C	jal    func24330 [$80024330]
    80076430	sw     v0, $0014(sp)
    80076434	addu   s0, v0, zero
    80076438	addu   a0, s0, zero
    8007643C	lui    v0, $800b
    80076440	lw     v0, $efe4(v0)
    80076444	ori    a1, zero, $0020
    80076448	addu   v0, s2, v0
    8007644C	jal    func231cc [$800231cc]
    80076450	sw     s0, $0004(v0)
}

80076454	addu   a0, s0, zero
80076458	addu   a1, zero, zero
8007645C	addiu  a2, sp, $0020
80076460	sll    v0, s3, $01
80076464	addu   v0, v0, s3
80076468	sll    v0, v0, $03
8007646C	subu   v0, v0, s3
80076470	lui    v1, $800b
80076474	lw     v1, $efe4(v1)
80076478	sll    s1, v0, $02
8007647C	addu   v1, s1, v1
80076480	lhu    v0, $005a(v1)
80076484	addiu  a3, sp, $0024
80076488	ori    v0, v0, $0001
8007648C	sh     v0, $005a(v1)
80076490	addiu  v0, sp, $0028
80076494	jal    func1f434 [$8001f434]
80076498	sw     v0, $0010(sp)
8007649C	addu   a0, s0, zero
800764A0	jal    func21a48 [$80021a48]
800764A4	ori    a1, zero, $0003
800764A8	lui    v1, $8005
800764AC	lw     v1, $e9b0(v1)
800764B0	ori    v0, zero, $0c00
800764B4	sh     v0, $002c(s0)
800764B8	ori    v0, zero, $2000
800764BC	bne    v1, zero, L765a0 [$800765a0]
800764C0	sh     v0, $0082(s0)
800764C4	lui    v0, $800b
800764C8	lw     v0, $efe4(v0)
800764CC	nop
800764D0	addu   v0, s1, v0
800764D4	lw     v0, $004c(v0)
800764D8	nop
800764DC	lw     v0, $0020(v0)
800764E0	nop
800764E4	sw     v0, $0000(s0)
800764E8	lui    v0, $800b
800764EC	lw     v0, $efe4(v0)
800764F0	nop
800764F4	addu   v0, s1, v0
800764F8	lw     v0, $004c(v0)
800764FC	nop
80076500	lw     v0, $0024(v0)
80076504	nop
80076508	sw     v0, $0004(s0)
8007650C	lui    v0, $800b
80076510	lw     v0, $efe4(v0)
80076514	nop
80076518	addu   v0, s1, v0
8007651C	lw     v0, $004c(v0)
80076520	nop
80076524	lw     v0, $0028(v0)
80076528	nop
8007652C	sw     v0, $0008(s0)
80076530	lui    v0, $800b
80076534	lw     v0, $efe4(v0)
80076538	nop
8007653C	addu   v0, s1, v0
80076540	lw     v1, $0024(v0)
80076544	lui    v0, $0001
80076548	sw     zero, $0010(s0)
8007654C	sw     zero, $000c(s0)
80076550	sw     zero, $0010(s0)
80076554	sw     zero, $0014(s0)
80076558	sw     v0, $001c(s0)
8007655C	bne    s7, zero, L76584 [$80076584]
80076560	sh     v1, $0084(s0)
80076564	lui    v0, $800b
80076568	lw     v0, $efe4(v0)
8007656C	lw     v1, $0024(sp)
80076570	addu   v0, s1, v0
80076574	lw     v0, $004c(v0)
80076578	sll    v1, v1, $01
8007657C	j      L765a0 [$800765a0]
80076580	sh     v1, $001a(v0)

L76584:	; 80076584
80076584	lui    v0, $800b
80076588	lw     v0, $efe4(v0)
8007658C	nop
80076590	addu   v0, s1, v0
80076594	lw     v1, $004c(v0)
80076598	ori    v0, zero, $0040
8007659C	sh     v0, $001a(v1)

L765a0:	; 800765A0
800765A0	lui    v0, $800b
800765A4	lh     v0, $1662(v0)
800765A8	nop
800765AC	beq    v0, zero, L765c4 [$800765c4]
800765B0	lui    v1, $0004
800765B4	lw     v0, $0040(s0)
800765B8	nop
800765BC	or     v0, v0, v1
800765C0	sw     v0, $0040(s0)

L765c4:	; 800765C4
800765C4	addu   a0, s0, zero

L765c8:	; 800765C8
800765C8	jal    func243e4 [$800243e4]
800765CC	addu   a1, zero, zero
800765D0	addu   a0, s0, zero
800765D4	jal    func21e40 [$80021e40]
800765D8	addu   a1, zero, zero
800765DC	ori    a0, zero, $0008
800765E0	jal    func322bc [$800322bc]
800765E4	addu   a1, zero, zero
800765E8	addu   a0, s0, zero
800765EC	lw     v0, $007c(s0)
800765F0	lui    a1, $8007
800765F4	addiu  a1, a1, $6104
800765F8	jal    func21a40 [$80021a40]
800765FC	sh     s3, $0014(v0)
if (FP == 0)
{
    80076608	jal    func23090 [$80023090]
    8007660C	addu   a0, s0, zero
    80076610	jal    func1c7f0 [$8001c7f0]
    80076614	nop
    80076618	lw     v0, $007c(s0)
    8007661C	nop
    80076620	lhu    v1, $000c(v0)
    80076624	ori    v0, zero, $00ff
    if (V1 == ff)
    {
        80076630	sll    v1, s3, $01
        80076634	addu   v1, v1, s3
        80076638	sll    v1, v1, $03
        8007663C	subu   v1, v1, s3
        80076640	lui    v0, $800b
        80076644	lw     v0, $efe4(v0)
        80076648	sll    v1, v1, $02
        8007664C	addu   v0, v1, v0
        80076650	lw     a0, $004c(v0)
        80076654	ori    v0, zero, $00ff
        80076658	sh     v0, $00ea(a0)
        8007665C	lui    v0, $800b
        80076660	lw     v0, $efe4(v0)
        80076664	nop
        80076668	addu   v0, v1, v0
        8007666C	lw     a1, $004c(v0)
        80076670	nop
        80076674	lw     v0, $0004(a1)
        80076678	lui    a0, $0100
        8007667C	or     v0, v0, a0
        80076680	sw     v0, $0004(a1)
        80076684	lui    v0, $800b
        80076688	lw     v0, $efe4(v0)
        8007668C	nop
        80076690	addu   v0, v1, v0
        80076694	lw     v0, $004c(v0)
        80076698	nop
        8007669C	lw     v0, $0020(v0)
        800766A0	nop
        800766A4	sw     v0, $0000(s0)
        800766A8	lui    v0, $800b
        800766AC	lw     v0, $efe4(v0)
        800766B0	nop
        800766B4	addu   v0, v1, v0
        800766B8	lw     v0, $004c(v0)
        800766BC	nop
        800766C0	lw     v0, $0024(v0)
        800766C4	nop
        800766C8	sw     v0, $0004(s0)
        800766CC	lui    v0, $800b
        800766D0	lw     v0, $efe4(v0)
        800766D4	nop
        800766D8	addu   v1, v1, v0
        800766DC	lw     v0, $004c(v1)
        800766E0	nop
        800766E4	lw     v0, $0028(v0)
        800766E8	nop
        800766EC	sw     v0, $0008(s0)
    }
}

V0 = w[800aefe4] + S3 * 5c;
V1 = w[V0 + 4c];
[V0 + 20] = w(h[V1 + 22]); // x
[V0 + 40] = w(h[V1 + 22]); // x

[V0 + 24] = w(h[V1 + 26]); // y
[V0 + 44] = w(h[V1 + 26]); // y

[V0 + 28] = w(h[V1 + 2a]); // z
[V0 + 48] = w(h[V1 + 2a]); // z

[S0 + 84] = h(w[V0 + 24]);

[S0 + 0] = w(w[V1 + 20]);
[S0 + 4] = w(w[V1 + 24]);
[S0 + 8] = w(w[V1 + 28]);

[800af148] = w(w[800af148] + 1);
////////////////////////////////



////////////////////////////////
// funca0224
current_entity_id = w[800af1f0];
struct_big = w[800af54c];
struct = w[800aefe4];
A2 = w[struct + current_entity_id * 5c + 4];

[struct + current_entity_id * 5c + 20] = w(h[struct_big + 22]);
[struct + current_entity_id * 5c + 24] = w(h[struct_big + 26]);
[struct + current_entity_id * 5c + 28] = w(h[struct_big + 2a]);
[struct + current_entity_id * 5c + 40] = w(h[struct_big + 22]);
[struct + current_entity_id * 5c + 44] = w(h[struct_big + 26]);
[struct + current_entity_id * 5c + 48] = w(h[struct_big + 2a]);

[A2 + 0] = w(w[struct_big + 20]);
[A2 + 4] = w(w[struct_big + 24]);
[A2 + 8] = w(w[struct_big + 28]);
[A2 + 10] = w(0);
[A2 + 84] = h(hu[struct_big + 26]);
[struct_big + 72] = h(hu[struct_big + 26])
////////////////////////////////



////////////////////////////////
// func9efe4
// FF   0000000000FF00
// FF   6600000000FFFF   DBFF000000FFFF
slot = A0;

field_script = w[800ad0d8];
S2 = bu[field_script + 0];
if (S2 == ff)
{
    entity_data = w[800af54c];
    [entity_data + 10] = h(bu[field_script + 1 + slot * 7 + 4]);

    A1 = 1 + slot * 7 + 0;
    func9d8c0;
    S0 = V0;

    A0 = 1 + slot * 7 + 2;
    func9d8c0;

    A0 = S0;
    A1 = V0;
    set_position_by_x_z;

    V0 = bu[field_script + 1 + slot * 7 + 5];
    if (V0 == ff)
    {
        A0 = 8;
        get_bytes_from_800C2F3C;
    }

    V0 = V1 + 4;
    V0 = V0 & 7;
    A1 = V0 << 9;
    [800aeeba] = h(A1);
    [800aeee0] = w((A1 << 10) >> 10);
    [800aeec4] = w((A1 << 10) >> 10);

    V0 = bu[field_script + 1 + slot * 7 + 6];
    if (V0 == ff)
    {
        A0 = 6;
        get_bytes_from_800C2F3C;
    }

    V0 = V0 - 2;
    V0 = V0 & 7;
    V0 = V0 << 9;

    [entity_data + 104] = h(V0 | 8000);
    [entity_data + 106] = h(V0 | 8000);
    [entity_data + 108] = h(V0 | 8000);
}

return 0;
////////////////////////////////



////////////////////////////////
// func9d8c0
V0 = w[800ad0d8];
return ((bu[V0 + A0 + 0] + (bu[V0 + A0 + 1] << 8)) << 10) >> 10;
////////////////////////////////