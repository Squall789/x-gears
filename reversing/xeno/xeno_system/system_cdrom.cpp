////////////////////////////////
// func42b20()

cd_1800 = w[80055e10]; // 1f801800

S2 = b[cd_1800] & 3;

loop42b54:	; 80042B54
    func4142c();
    S0 = V0;

    if( S0 == 0 )
    {
        [cd_1800] = b(S2);
        return;
    }
    if( ( S0 & 4 ) && ( w[80055b4c] != 0 ) )
    {
        A0 = bu[80055e29];
        A1 = 800598b4;
        80042B90	jalr   w[80055b4c] ra
    }
    if( ( S0 & 2 ) && ( w[80055b48] != 0 ) )
    {
        A0 = bu[80055e28];
        A1 = 800598ac;
        80042BC4	jalr   w[80055b48] ra
    }
80042BCC	j      loop42b54 [$80042b54]
////////////////////////////////



////////////////////////////////
// func41f00()
cdl_command = S0 = A0; // cdl command
param_ptr = S1 = A1; // pointer to params
S5 = A2;
S2 = A3;



// log debug text
if( w[80055b54] >= 2 )
{
    A0 = 80018f58; // "%s..."
    A1 = w[80055b70 + cdl_command * 4];
    80041F5C	jal    func199e8 [$800199e8]
}



// check number of arguments for cdl command
if( ( w[80055d90 + cdl_command * 4] != 0 ) && ( param_ptr == 0 ) )
{
    if( w[80055b54] > 0 )
    {
        A0 = 80018f60; // "%s: no param"
        A1 = w[80055b70 + cdl_command * 4];
        80041FB4	jal    func199e8 [$800199e8]
    }
    return -2;
}



A0 = 0;
A1 = 0;
func419b4();



if( cdl_command == 2 ) // CdlSetloc
{
    A0 = 0;
    loop41fe4:	; 80041FE4
        [80055b64 + A0] = b(bu[param_ptr + A0]);
        A0 = A0 + 1;
        V0 = A0 < 4;
    80041FFC	bne    v0, zero, loop41fe4 [$80041fe4]
}

if( cdl_command == e ) // CdlSetmode
{
    [80055b68] = b(bu[param_ptr]);
}



// resets interrupt
[80055e28] = b(0);
if( w[80055c90 + cdl_command * 4] != 0 )
{
    [80055e29] = b(0);
}



80042054	lui    v0, $8005
80042058	lw     v0, $5e10(v0)
80042060	sb     zero, $0000(v0)

if( w[80055d90 + cdl_command * 4] > 0 )
{
    A0 = 0;
    loop42084:	; 80042084
        cd_1802 = w[80055e18];
        [cd_1802] = b(bu[S1 + A0]);
        A0 = A0 + 1;
        V0 = A0 < w[80055d90 + cdl_command * 4];
    800420A4	bne    v0, zero, loop42084 [$80042084]
}

800420AC	lui    v0, $8005
800420B0	lw     v0, $5e14(v0)
800420B4	lui    at, $8005
800420B8	sb     s0, $5b69(at)
800420BC	sb     s0, $0000(v0)

if( S2 != 0 )
{
    return 0;
}

A0 = -1;
func4b3f4();


800420D0	addiu  v0, v0, $03c0
800420D4	lui    a0, $8005
800420D8	addiu  a0, a0, $5e28
800420DC	lui    at, $8006
800420E0	sw     v0, $98c4(at)
800420E4	lui    at, $8006
800420E8	sw     zero, $98c8(at)
800420EC	lbu    v1, $0000(a0)

V0 = 80018f70; // "CD_cw"
[800598cc] = w(V0);
if( V1 == 0 )
{
    80042108	lui    s3, $8005
    8004210C	addiu  s3, s3, $5bf0
    80042110	addu   s2, a0, zero
    80042114	addiu  s4, s2, $0001

    loop42118:	; 80042118
        A0 = -1;
        func4b3f4();

        V1 = w[800598c4];

        8004212C	slt    v1, v1, v0
        80042130	bne    v1, zero, L42160 [$80042160]
        80042134	nop
        80042138	lui    v1, $8006
        8004213C	lw     v1, $98c8(v1)
        80042144	addiu  v0, v1, $0001
        80042148	lui    at, $8006
        8004214C	sw     v0, $98c8(at)

        if( V1 > 003c0000 )
        {
            L42160:	; 80042160
            A0 = 80018ebc; // "CD timeout: "
            80042168	jal    func42c04 [$80042c04]

            80042170	lbu    a0, $0000(s2)
            80042174	lbu    v0, $0001(s2)
            80042178	lui    a1, $8006
            8004217C	lw     a1, $98cc(a1)
            80042180	sll    v0, v0, $02
            80042184	addu   v0, v0, s3
            80042188	sll    a0, a0, $02
            8004218C	lw     v1, $0000(v0)
            80042190	lui    v0, $8005
            80042194	lbu    v0, $5b69(v0)
            80042198	addu   a0, a0, s3
            8004219C	sll    v0, v0, $02
            800421A0	sw     v1, $0010(sp)
            800421A4	lui    at, $8005
            800421A8	addu   at, at, v0
            800421AC	lw     a2, $5b70(at)
            800421B0	lw     a3, $0000(a0)

            A0 = 80018ecc; // "%s:(%s) Sync=%s, Ready=%s"
            800421BC	jal    func199e8 [$800199e8]
            800421C0	nop
            800421C4	jal    func423a4 [$800423a4]
            800421C8	nop
            800421CC	j      L421d8 [$800421d8]
            800421D0	addiu  v0, zero, $ffff (=-$1)
        }

        800421D4	addu   v0, zero, zero

        L421d8:	; 800421D8
        if( V0 != 0 )
        {
            return -1;
        }

        800421E0	jal    func4b73c [$8004b73c]
        800421E4	nop
        800421E8	beq    v0, zero, L42298 [$80042298]
        800421EC	nop
        800421F0	lui    v0, $8005
        800421F4	lw     v0, $5e10(v0)
        800421F8	nop
        800421FC	lbu    v0, $0000(v0)
        80042200	nop
        80042204	andi   s1, v0, $0003

        loop42208:	; 80042208
            func4142c();
            S0 = V0;

            if( S0 == 0 )
            {
                break;
            }
            if( ( S0 & 4 ) && ( w[80055b4c] != 0 ) )
            {
                A0 = bu[S4];
                A1 = 800598b4;
                80042244	jalr   w[80055b4c] ra
            }
            if( ( S0 & 2 ) && ( w[80055b48] != 0 ) )
            {
                A0 = bu[S2];
                A1 = 800598ac;
                80042278	jalr   w[80055b48] ra
            }
        80042280	j      loop42208 [$80042208]

        80042288	lui    v0, $8005
        8004228C	lw     v0, $5e10(v0)
        80042290	nop
        80042294	sb     s1, $0000(v0)

        L42298:	; 80042298
        80042298	lbu    v0, $0000(s2)
    800422A0	beq    v0, zero, loop42118 [$80042118]
}

80042104	addu   a2, s5, zero
800422A8	lui    a0, $8006
800422AC	addiu  a0, a0, $98ac (=-$6754)
800422B0	beq    a2, zero, L422d8 [$800422d8]
800422B4	nop
800422B8	addiu  v1, zero, $0007
800422BC	addiu  a1, zero, $ffff (=-$1)

loop422c0:	; 800422C0
800422C0	lbu    v0, $0000(a0)
800422C4	addiu  a0, a0, $0001
800422C8	addiu  v1, v1, $ffff (=-$1)
800422CC	sb     v0, $0000(a2)
800422D0	bne    v1, a1, loop422c0 [$800422c0]
800422D4	addiu  a2, a2, $0001

L422d8:	; 800422D8
800422D8	lui    v0, $8005
800422DC	addiu  v0, v0, $5e28
800422E0	lbu    v0, $0000(v0)
800422E4	nop
800422E8	xori   v0, v0, $0005
800422EC	sltiu  v0, v0, $0001
return 0 - V0;
////////////////////////////////



////////////////////////////////
// func41c34
80041C3C	addu   s7, a0, zero
80041C44	addu   s4, a1, zero
80041C48	addiu  a0, zero, $ffff (=-$1)
80041C64	jal    func4b3f4 [$8004b3f4]

80041C6C	lui    s5, $8005
80041C70	addiu  s5, s5, $5bf0
80041C74	lui    s2, $8005
80041C78	addiu  s2, s2, $5e28
80041C7C	addiu  s6, s2, $0001
80041C80	addiu  s3, s2, $0002
80041C84	addiu  v0, v0, $03c0
80041C88	lui    at, $8006
80041C8C	sw     v0, $98c4(at)

V0 = 80018f4c; // "CD_ready"
80041C98	lui    at, $8006
80041C9C	sw     zero, $98c8(at)
80041CA0	lui    at, $8006
80041CA4	sw     v0, $98cc(at)

L41ca8:	; 80041CA8
80041CA8	jal    func4b3f4 [$8004b3f4]
80041CAC	addiu  a0, zero, $ffff (=-$1)
80041CB0	lui    v1, $8006
80041CB4	lw     v1, $98c4(v1)
80041CB8	nop
80041CBC	slt    v1, v1, v0
80041CC0	bne    v1, zero, L41cf0 [$80041cf0]
80041CC4	nop
80041CC8	lui    v1, $8006
80041CCC	lw     v1, $98c8(v1)
80041CD0	nop
80041CD4	addiu  v0, v1, $0001
80041CD8	lui    at, $8006
80041CDC	sw     v0, $98c8(at)
80041CE0	lui    v0, $003c
80041CE4	slt    v0, v0, v1
80041CE8	beq    v0, zero, L41d64 [$80041d64]
80041CEC	nop

L41cf0:	; 80041CF0
A0 = 80018ebc; // "CD timeout: "
80041CF8	jal    func42c04 [$80042c04]

80041D00	lbu    a0, $0000(s2)
80041D04	lbu    v0, $0001(s2)
80041D08	lui    a1, $8006
80041D0C	lw     a1, $98cc(a1)
80041D10	sll    v0, v0, $02
80041D14	addu   v0, v0, s5
80041D18	sll    a0, a0, $02
80041D1C	lw     v1, $0000(v0)
80041D20	lui    v0, $8005
80041D24	lbu    v0, $5b69(v0)
80041D28	addu   a0, a0, s5
80041D2C	sll    v0, v0, $02
80041D30	sw     v1, $0010(sp)
80041D34	lui    at, $8005
80041D38	addu   at, at, v0
80041D3C	lw     a2, $5b70(at)
80041D40	lw     a3, $0000(a0)

A0 = 80018ecc; // "%s:(%s) Sync=%s, Ready=%s"
80041D4C	jal    func199e8 [$800199e8]
80041D50	nop
80041D54	jal    func423a4 [$800423a4]
80041D58	nop
80041D5C	j      L41d68 [$80041d68]
80041D60	addiu  v0, zero, $ffff (=-$1)

L41d64:	; 80041D64
80041D64	addu   v0, zero, zero

L41d68:	; 80041D68
80041D68	bne    v0, zero, L41ed0 [$80041ed0]
80041D6C	addiu  v0, zero, $ffff (=-$1)
80041D70	jal    func4b73c [$8004b73c]
80041D74	nop
80041D78	beq    v0, zero, L41e28 [$80041e28]
80041D7C	nop
80041D80	lui    v0, $8005
80041D84	lw     v0, $5e10(v0)
80041D88	nop
80041D8C	lbu    v0, $0000(v0)
80041D90	nop
80041D94	andi   s1, v0, $0003

loop41d98:	; 80041D98
    func4142c();
    S0 = V0;

    if( S0 == 0 )
    {
        break;
    }
    if( ( S0 & 4 ) && ( w[80055b4c] != 0 ) )
    {
        A0 = bu[S6];
        A1 = 800598b4;
        80041DD4	jalr   w[80055b4c] ra
    }
    if( ( S0 & 2 ) && ( w[80055b48] != 0 ) )
    {
        A0 = bu[S2];
        A1 = 800598ac;
        80041E08	jalr   w[80055b48] ra
    }
80041E10	j      loop41d98 [$80041d98]

80041E18	lui    v0, $8005
80041E1C	lw     v0, $5e10(v0)
80041E20	nop
80041E24	sb     s1, $0000(v0)

L41e28:	; 80041E28
80041E28	lbu    v0, $0000(s3)
80041E2C	nop
80041E30	andi   a2, v0, $00ff
80041E34	beq    a2, zero, L41e78 [$80041e78]
80041E38	nop
80041E3C	sb     zero, $0000(s3)
80041E40	lui    a0, $8006
80041E44	addiu  a0, a0, $98bc (=-$6744)
80041E48	beq    s4, zero, L41ec0 [$80041ec0]
80041E4C	addu   a1, s4, zero
80041E50	addiu  v1, zero, $0007
80041E54	addiu  a3, zero, $ffff (=-$1)

loop41e58:	; 80041E58
80041E58	lbu    v0, $0000(a0)
80041E5C	addiu  a0, a0, $0001
80041E60	addiu  v1, v1, $ffff (=-$1)
80041E64	sb     v0, $0000(a1)
80041E68	bne    v1, a3, loop41e58 [$80041e58]
80041E6C	addiu  a1, a1, $0001
80041E70	j      L41ed0 [$80041ed0]
80041E74	addu   v0, a2, zero

L41e78:	; 80041E78
80041E78	lbu    v0, $ffff(s3)
80041E7C	nop
80041E80	andi   a2, v0, $00ff
80041E84	beq    a2, zero, L41ec8 [$80041ec8]
80041E88	nop
80041E8C	sb     zero, $ffff(s3)
80041E90	addu   a1, s4, zero
80041E94	lui    a0, $8006
80041E98	addiu  a0, a0, $98b4 (=-$674c)
80041E9C	beq    a1, zero, L41ec0 [$80041ec0]
80041EA0	addiu  v1, zero, $0007
80041EA4	addiu  a3, zero, $ffff (=-$1)

loop41ea8:	; 80041EA8
80041EA8	lbu    v0, $0000(a0)
80041EAC	addiu  a0, a0, $0001
80041EB0	addiu  v1, v1, $ffff (=-$1)
80041EB4	sb     v0, $0000(a1)
80041EB8	bne    v1, a3, loop41ea8 [$80041ea8]
80041EBC	addiu  a1, a1, $0001

L41ec0:	; 80041EC0
80041EC0	j      L41ed0 [$80041ed0]
80041EC4	addu   v0, a2, zero

L41ec8:	; 80041EC8
80041EC8	beq    s7, zero, L41ca8 [$80041ca8]
80041ECC	addu   v0, zero, zero

L41ed0:	; 80041ED0
////////////////////////////////



////////////////////////////////
// func419b4()
S5 = A0;
S6 = A1;

A0 = -1;
func4b3f4();

[800598c4] = w(V0 + 3c0);
[800598c8] = w(0);
[800598cc] = w(80018f44); // "CD_sync"

L41a20:	; 80041A20
    A0 = -1;
    func4b3f4();

    V1 = w[800598c4] < V0;
    80041A38	bne    v1, zero, L41a68 [$80041a68]

    V1 = w[800598c8];
    [800598c8] = w(V1 + 1);

    if( V1 > 003c0000 )
    {
        L41a68:	; 80041A68
        A0 = 80018ebc; // "CD timeout: "
        80041A70	jal    func42c04 [$80042c04]

        A0 = 80018ecc; // "%s:(%s) Sync=%s, Ready=%s"
        A1 = w[800598cc];
        V0 = bu[80055b69];
        A2 = w[80055b70 + V0 * 4];
        V0 = bu[80055e28];
        A3 = w[80055bf0 + V0 * 4];
        V0 = bu[80055e29];
        A4 = w[80055bf0 + V0 * 4];
        80041AC4	jal    func199e8 [$800199e8]

        func423a4();

        return -1;
    }



    if( hu[80056f46] != 0 )
    {
        V0 = w[80055e10];
        S1 = bu[V0] & 03;

        loop41b10:	; 80041B10
            func4142c();
            S0 = V0;

            if( S0 == 0 )
            {
                break;
            }
            if( ( S0 & 4 ) && ( w[80055b4c] != 0 ) )
            {
                A0 = bu[80055e29];
                A1 = 800598b4;
                80041B4C	jalr   w[80055b4c] ra
            }
            if( ( S0 & 2 ) && ( w[80055b48] != 0 ) )
            {
                A0 = bu[80055e28];
                A1 = 800598ac;
                80041B80	jalr   w[80055b48] ra
            }
        80041B88	j      loop41b10 [$80041b10]

        V0 = w[80055e10];
        [V0] = b(S1);
    }

    if( ( bu[80055e28] == 2 ) || ( bu[80055e28] == 5 ) )
    {
        [80055e28] = b(2);

        if( S6 != 0 )
        {
            V1 = 7;
            A0 = 0;
            loop41be0:	; 80041BE0
                V0 = bu[800598ac + A0];
                A0 = A0 + 1;
                V1 = V1 - 1;
                [S6 + A0] = b(V0);
            80041BF0	bne    v1, -1, loop41be0 [$80041be0]
        }

        return bu[80055e28];
    }

80041C00	beq    s5, zero, L41a20 [$80041a20]

return 0;
////////////////////////////////



////////////////////////////////
// func4142c()

cd_1800 = w[80055e10]; // 1f801800
cd_1801 = w[80055e14]; // 1f801801
cd_1802 = w[80055e18]; // 1f801802
cd_1803 = w[80055e1c]; // 1f801803

[cd_1800] = b(01); // set index to 1



// get interrupt and check it
V0 = bu[cd_1803] & 07; // response received INT1..INT7
[SP + 10] = b(V0);
if( V0 == 0 )
{
    return 0;
}



// get last interrupt
80041478	j      L41490 [$80041490]
loop41480:	; 80041480
    [SP + 10] = b(bu[cd_1803] & 07);
    L41490:	; 80041490
    V0 = bu[cd_1803] & 07;
    V1 = bu[SP + 10];
8004149C	bne    v1, v0, loop41480 [$80041480]



// store response fifo
S0 = 0;
loop414a8:	; 800414A8
    if( ( bu[cd_1800] & 20 ) == 0 ) // response fifo empty (0 = Empty)
    {
        break;
    }
    // store index1 - response fifo
    [SP + 18 + S0] = b(bu[cd_1801]);
    S0 = S0 + 1;
    V0 = S0 < 8;
800414E4	bne    v0, zero, loop414a8 [$800414a8]



// store rest of fifo stored data as 0
if( S0 < 8 )
{
    V1 = S0;
    loop41500:	; 80041500
        [SP + 18 + V1] = b(0);
        V1 = V1 + 1;
        V0 = V1 < 8;
    8004150C	bne    v0, zero, loop41500 [$80041500]
}



[cd_1800] = b(01);
[cd_1803] = b(07);
[cd_1802] = b(07);



S1 = 0;
V0 = bu[80055b69];
if( ( bu[SP + 10] != 3 ) || ( w[80055d10 + V0 * 4] != 0 ) )
{
    if( ( w[80055b58] & 00000010 ) == 0 )
    {
        // shell open once shell open (0 = closed, 1 = is/was open)
        if( bu[SP + 18] & 10 )
        {
            [80055b60] = w(w[80055b60] + 1);
        }
    }

    S1 = bu[SP + 18] & 1d;
    [80055b58] = w(bu[SP + 18]);
    [80055b5c] = w(bu[SP + 19]);
}



// CdlDiskError
if( bu[SP + 10] == 5 )
{
    if( w[80055b54] > 0 )
    {
        A0 = 80018ee8; // "DiskError:"
        80041614	jal    func199e8 [$800199e8]

        if( w[80055b54] > 0 )
        {
            A0 = 80018ef4; // "com=%s,code=(%02x:%02x)"
            V0 = bu[80055b69];
            A1 = w[80055b70 + V0 * 4];
            A2 = w[80055b58];
            A3 = w[80055b5c];
            80041660	jal    func199e8 [$800199e8]
        }
    }
}



switch( bu[SP + 10] )
{
    case 1: // CdlDataReady
    {
        if( S1 == 0 )
        {
            [80055e29] = b(1); // CdlDataReady
        }
        else
        {
            if( S0 == 1 )
            {
                S1 = 0;
            }

            if( S1 == 0 )
            {
                [80055e29] = b(1); // CdlDataReady
            }
            else
            {
                [80055e29] = b(5); // CdlDiskError
            }
        }

        A1 = 0;
        A0 = 7;
        loop41828:	; 80041828
            [800598b4 + A1] = b(bu[SP + 18 + A1]);
            A1 = A1 + 1;
            A0 = A0 - 1;
        80041838	bne    a0, -1, loop41828 [$80041828]

        [cd_1800] = b(0);
        [cd_1803] = b(0);
        return 4;
    }
    break;

    case 2: // CdlComplete
    {
        if( S1 == 0 )
        {
            [80055e29] = b(2); // CdlComplete
        }
        else
        {
            [80055e29] = b(5); // CdlDiskError
        }

        A1 = 0;
        A0 = 7;
        loop41828:	; 80041828
            [800598ac + A1] = b(bu[SP + 18 + A1]);
            A1 = A1 + 1;
            A0 = A0 - 1;
        80041838	bne    a0, -1, loop41828 [$80041828]

        return 2;
    }
    break;

    case 3: // CdlAcknowledge
    {
        if( S1 == 0 )
        {
            V0 = bu[80055b69];
            if( w[80055c10 + V0 * 4] == 0 )
            {
                [80055e28] = b(2);

                A1 = 0;
                A0 = 7;
                loop41828:	; 80041828
                    [800598ac + A1] = b(bu[SP + 18 + A1]);
                    A1 = A1 + 1;
                    A0 = A0 - 1;
                80041838	bne    a0, -1, loop41828 [$80041828]

                return 2;
            }
            else
            {
                [80055e28] = b(3);

                A1 = 0;
                A0 = 7;
                loop41828:	; 80041828
                    [800598ac + A1] = b(bu[SP + 18 + A1]);
                    A1 = A1 + 1;
                    A0 = A0 - 1;
                80041838	bne    a0, -1, loop41828 [$80041828]

                return 1;
            }
        }
        else
        {
            [80055e28] = b(5);

            A1 = 0;
            A0 = 7;
            loop41828:	; 80041828
                [800598ac + A1] = b(bu[SP + 18 + A1]);
                A1 = A1 + 1;
                A0 = A0 - 1;
            80041838	bne    a0, -1, loop41828 [$80041828]

            return 2;
        }
    }
    break;

    case 4: // CdlDataEnd
    {
        [80055e29] = b(4);
        [80055e2a] = b(4);

        A1 = 0;
        A0 = 7;
        loop41828:	; 80041828
            [800598bc + A1] = b(bu[SP + 18 + A1]);
            A1 = A1 + 1;
            A0 = A0 - 1;
        80041838	bne    a0, -1, loop41828 [$80041828]

        A1 = 0;
        A0 = 7;
        loop41828:	; 80041828
            [800598b4 + A1] = b(bu[SP + 18 + A1]);
            A1 = A1 + 1;
            A0 = A0 - 1;
        80041838	bne    a0, -1, loop41828 [$80041828]

        return 4;
    }
    break;

    case 5: // CdlDiskError
    {
        [80055e28] = b(5);
        [80055e29] = b(5);

        A1 = 0;
        A0 = 7;
        loop41828:	; 80041828
            [800598ac + A1] = b(bu[SP + 18 + A1]);
            A1 = A1 + 1;
            A0 = A0 - 1;
        80041838	bne    a0, -1, loop41828 [$80041828]

        A1 = 0;
        A0 = 7;
        loop41828:	; 80041828
            [800598b4 + A1] = b(bu[SP + 18 + A1]);
            A1 = A1 + 1;
            A0 = A0 - 1;
        80041838	bne    a0, -1, loop41828 [$80041828]

        return 6;
    }

    default:
    {
        A0 = 80018f10; // "CDROM: unknown intr"
        8004197C	jal    func42c04 [$80042c04]

        A0 = 80018f24; // "(%d)"
        A1 = bu[SP + 10];
        80041990	jal    func199e8 [$800199e8]

        return 0;
    }
}
////////////////////////////////



////////////////////////////////
// func4b3f4()

V0 = w[80056edc];
V1 = w[80056ee0];
S0 = w[V0];
V0 = w[V1];

S1 = V0 - w[80056ee4];

if( A0 < 0 )
{
    return w[80058000];
}
if( A0 == 1 )
{
    return S1;
}

if( A0 > 0 )
{
    V0 = w[80056ee8] - 1 + A0;
}
else
{
    V0 = w[80056ee8];
}

A1 = 0;
if( A0 > 0 )
{
    A1 = A0 - 1;
}

A0 = V0;
func4b53c();

V0 = w[80056edc];
S0 = w[V0];

A0 = w[80058000] + 1;
A1 = 1;
func4b53c();

if( S0 & 00400000 )
{
    V1 = w[80056edc];
    V0 = w[V1];
    V0 = S0 XOR V0;
    if( V0 >= 0 )
    {
        loop4b4e4:	; 8004B4E4
            8004B4E4	lw     v0, $0000(v1)
            8004B4EC	xor    v0, s0, v0
            V0 = V0 & 80000000;
        8004B4F4	beq    v0, zero, loop4b4e4 [$8004b4e4]
    }
}

V1 = w[80056ee0];
[80056ee8] = w(w[80058000]);
[80056ee4] = w(w[V1]);

return S1;
////////////////////////////////



////////////////////////////////
// func4b53c()

wait = A1 << f;

if( w[80058000] < A0 )
{
    loop4b564:	; 8004B564
        wait = wait - 1;
        if( wait == -1 )
        {
            A0 = 80019458; // "VSync: timeout"
            8004B58C	jal    func42c04 [$80042c04]

            A0 = 0;
            system_bios_change_clear_pad();

            A0 = 3; // vblank
            A1 = 0; // do nothing
            system_bios_change_clear_rcnt();

            break;
        }

        V0 = w[80058000] < A0;
    8004B5C0	bne    v0, zero, loop4b564 [$8004b564]
}
////////////////////////////////



////////////////////////////////
// func423a4()
800423A4	lui    v1, $8005
800423A8	lw     v1, $5e10(v1)
800423AC	addiu  v0, zero, $0001
800423B0	sb     v0, $0000(v1)
800423B4	lui    v0, $8005
800423B8	lw     v0, $5e1c(v0)
800423BC	nop
800423C0	lbu    v0, $0000(v0)
800423C4	nop
800423C8	andi   v0, v0, $0007
800423CC	beq    v0, zero, L42428 [$80042428]
800423D0	addiu  a0, zero, $0001
800423D4	addiu  v1, zero, $0007

loop423d8:	; 800423D8
800423D8	lui    v0, $8005
800423DC	lw     v0, $5e10(v0)
800423E0	nop
800423E4	sb     a0, $0000(v0)
800423E8	lui    v0, $8005
800423EC	lw     v0, $5e1c(v0)
800423F0	nop
800423F4	sb     v1, $0000(v0)
800423F8	lui    v0, $8005
800423FC	lw     v0, $5e18(v0)
80042400	nop
80042404	sb     v1, $0000(v0)
80042408	lui    v0, $8005
8004240C	lw     v0, $5e1c(v0)
80042410	nop
80042414	lbu    v0, $0000(v0)
80042418	nop
8004241C	andi   v0, v0, $0007
80042420	bne    v0, zero, loop423d8 [$800423d8]
80042424	nop

L42428:	; 80042428
80042428	lui    at, $8005
8004242C	sb     zero, $5e2a(at)
80042430	lui    v0, $8005
80042434	lbu    v0, $5e2a(v0)
80042438	lui    a0, $8005
8004243C	lw     a0, $5e10(a0)
80042440	lui    v1, $8005
80042444	addiu  v1, v1, $5e28
80042448	lui    at, $8005
8004244C	sb     v0, $5e29(at)
80042450	addiu  v0, zero, $0002
80042454	sb     v0, $0000(v1)
80042458	sb     zero, $0000(a0)
8004245C	lui    v0, $8005
80042460	lw     v0, $5e1c(v0)
80042464	nop
80042468	sb     zero, $0000(v0)
8004246C	lui    v1, $8005
80042470	lw     v1, $5e20(v1)
80042474	addiu  v0, zero, $1325
80042478	sw     v0, $0000(v1)
8004247C	jr     ra 
80042480	nop
////////////////////////////////



////////////////////////////////
// func40e2c()
V0 = w[80055b48];
[80055b48] = w(A0);
return V0;
////////////////////////////////



////////////////////////////////
// func40e44()
V0 = w[80055b4c];
[80055b4c] = w(A0);
return V0;
////////////////////////////////