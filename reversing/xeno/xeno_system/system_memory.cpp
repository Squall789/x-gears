////////////////////////////////
// system_memory_allocate()

// insert new record to allocated memory list and return pointer to data
// -4 [][][][] flags.
//              0x001fffff - place in code from where we call allocate function.
//              0x01e00000 - hu[GP + 1ac] & 000f.
//                     0x3 - model data.
//              0x02000000 - set to 0.
//              0xfc000000 - hu[GP + 1a8].
//                    0x25 - model packets.
//                    0x26 - lighting data.
//                    0x2b - init +1c in model data.
//                    0x2c - model vertexes.
//                    0x2d - [part_header + c].
// -8 [][][][] pointer to next element.

alloc_size = A0;
flag = A1;



// get place from which we called alloc for debug purpose
alloc_call_addr = RA - 8;
[GP + 1d0] = w(alloc_call_addr);
alloc_call_word = (alloc_call_addr << 7) >> 9;



if( w[GP + 1bc] != 0 )
{
    func31e1c();
}



[GP + 1cc] = w(alloc_size);
aligned_size = (alloc_size + 3) & fffffffc; // align to size of word



not_use_min_lowest = 1;
min_free_data = 0;
lowest_free_data = 0;
free_data = 0;
min_free_space = 800000;
data = w[GP + 1b0];
loop31a68:	; 80031A68
    if( ( w[data - 4] & 01e00000 ) != 0 )
    {
        loop31a7c:	; 80031A7C
            if( ( w[data - 4] & 01e00000 ) == 00200000 )
            {
                if( ( ( w[GP + 1c0] == 0 ) && ( not_use_min_lowest != 0 ) ) || ( not_use_min_lowest == 0 ) )
                {
                    if( not_use_min_lowest != 0 )
                    {
                        A0 = 82;
                        func19b50();
                    }

                    if( flag != 1 )
                    {
                        [min_free_data + aligned_size + 0] = w(w[free_data - 8]);
                        [min_free_data + aligned_size + 4] = w(w[free_data - 4]);

                        [free_data - 8] = w(min_free_data + aligned_size + 8);
                        [free_data - 4] = w((w[free_data - 4] & fe1fffff) | ((hu[GP + 1ac] & 000f) << 15)); // set 0x01e00000
                        [free_data - 4] = w((w[free_data - 4] & 03ffffff) | (hu[GP + 1a8] << 1a));          // set 0xfc000000
                        [free_data - 4] = w(w[free_data - 4]) & fdffffff);                                  // set 0x02000000
                        [free_data - 4] = w((w[free_data - 4] & ffe00000) | (alloc_call_word & 001fffff));  // set 0x001fffff (place in code from where we call allocate function)
                        [GP + 1a8] = h(20);
                        return min_free_data;
                    }
                    else
                    {
                        if( free_data < lowest_free_data )
                        {
                            [lowest_free_data - 4] = w((w[lowest_free_data - 4] & fe1fffff) | ((hu[GP + 1ac] & 000f) << 15)); // set 0x01e00000
                            [lowest_free_data - 4] = w((w[lowest_free_data - 4] & 03ffffff) | (hu[GP + 1a8] << 1a));          // set 0xfc000000
                            [lowest_free_data - 4] = w(w[lowest_free_data - 4]) & fdffffff);                                  // set 0x02000000
                            [lowest_free_data - 4] = w((w[lowest_free_data - 4] & ffe00000) | (alloc_call_word & 001fffff));  // set 0x001fffff (place in code from where we call allocate function)
                            [GP + 1a8] = h(20);
                            return lowest_free_data;
                        }
                        else
                        {
                            V0 = w[free_data - 8] - aligned_size;
                            [V0 + 0] = w(w[free_data + 0]);
                            [V0 + 4] = w((w[V0 + 4] & fe1fffff) | ((hu[GP + 1ac] & 000f) << 15)); // set 0x01e00000
                            [V0 + 4] = w((w[V0 + 4] & 03ffffff) | (hu[GP + 1a8] << 1a));          // set 0xfc000000
                            [V0 + 4] = w(w[V0 + 4]) & fdffffff);                                  // set 0x02000000
                            [V0 + 4] = w((w[V0 + 4] & ffe00000) | (alloc_call_word & 001fffff));  // set 0x001fffff (place in code from where we call allocate function)
                            [free_data - 8] = w(V0);
                            [GP + 1a8] = h(20);
                            return V0;
                        }
                    }
                }

                return 0;
            }

            data = w[data - 8];
            V0 = w[data - 4] & 01e00000;
        80031AA4	bne    v0, zero, loop31a7c [$80031a7c]
    }



    free_space = w[data - 8] - data - 18;



    if( ( ( free_space - aligned_size ) == 4 ) || ( ( free_space - aligned_size ) == 0 ) )
    {
        if( flag != 1 )
        {
            [data - 4] = w((w[data - 4] & fe1fffff) | ((hu[GP + 1ac] & 000f) << 15)); // set 0x01e00000
            [data - 4] = w((w[data - 4] & 03ffffff) | (hu[GP + 1a8] << 1a));          // set 0xfc000000
            [data - 4] = w(w[data - 4]) & fdffffff);                                  // set 0x02000000
            [data - 4] = w((w[data - 4] & ffe00000) | (alloc_call_word & 001fffff));  // set 0x001fffff (place in code from where we call allocate function)
            [GP + 1a8] = h(20);
            return data;
        }
        not_use_min_lowest = 0;
        lowest_free_data = data;
    }
    else if( ( free_space - aligned_size ) >= 5 )
    {
        not_use_min_lowest = 0;

        if( flag == 1 )
        {
            free_data = data;
        }
        else if( flag != 2 )
        {
            [data + aligned_size + 0] = w(w[data - 8]);
            [data + aligned_size + 4] = w(w[data - 4]);

            [data - 8] = w(data + aligned_size + 8);
            [data - 4] = w((w[data - 4] & fe1fffff) | ((hu[GP + 1ac] & 000f) << 15)); // set 0x01e00000
            [data - 4] = w((w[data - 4] & 03ffffff) | (hu[GP + 1a8] << 1a));          // set 0xfc000000
            [data - 4] = w(w[data - 4]) & fdffffff);                                  // set 0x02000000
            [data - 4] = w((w[data - 4] & ffe00000) | (alloc_call_word & 001fffff));  // set 0x001fffff (place in code from where we call allocate function)
            [GP + 1a8] = h(20);
            return data;
        }
        else if( free_space < min_free_space )
        {
            free_data = data;
            min_free_data = data;
            min_free_space = free_space;
        }
    }

    data = w[data - 8];
80031BB0	j      loop31a68 [$80031a68]
////////////////////////////////



////////////////////////////////
// func31e1c()
data = w[GP + 1b0];
if( ( w[data - 4] & 01e00000 ) != 00200000 )
{
    loop31e48:	; 80031E48
        if( ( w[data - 4] & 01e00000 ) == 0 )
        {
            next_data = w[data - 8];
            if( ( w[next_data - 4] & 01e00000 ) == 0 )
            {
                loop31e80:	; 80031E80
                    next_data = w[next_data - 8];
                    [data - 8] = w(next_data);
                    if( ( w[data - 4] & 01e00000 ) != 0 )
                    {
                        break;
                    }
                    V0 = w[next_data - 4] & 01e00000;
                80031E98	beq    v0, zero, loop31e80 [$80031e80]
            }
        }
        data = w[data - 8];
        V0 = w[data - 4] & 01e00000;
    80031EB4	bne    v0, 00200000, loop31e48 [$80031e48]
}
[GP + 1bc] = w(0);
////////////////////////////////



////////////////////////////////
// system_copy_memory()
if( A0 == 0 )
{
    return 0;
}
V1 = A0;
if( A2 > 0 )
{
    loop3f820:	; 8003F820
        [A0] = b(bu[A1]);
        A0 = A0 + 1;
        A1 = A1 + 1;
        A2 = A2 - 1;
    8003F830	bgtz   a2, loop3f820 [$8003f820]
}
return V1;
////////////////////////////////



////////////////////////////////
// func31d94()
part_header = A0;
offset24 = A1;

T2 = w[part_header - 8];
if( offset24 + 10 < T2 - part_header - 8 )
{
    [GP + 1bc] = w(1);
    [part_header + offset24 + 0] = w(T2);
    [part_header + offset24 + 4] = w(w[part_header + offset24 + 4] & fe1fffff & 03ffffff | 84000000 & ffe00000 & fdffffff);
    [part_header - 8] = w(part_header + offset24 + 8);
    return part_header - 8;
}

return 0;
////////////////////////////////



////////////////////////////////
// func31ec8()
[A0 - 4] = w(w[A0 - 4] | 02000000);
////////////////////////////////



////////////////////////////////
// func31edc()
[A0 - 4] = w(w[A0 - 4] & fdffffff);
////////////////////////////////



////////////////////////////////
// func322bc()
[GP + 1ac] = h(A0);
[80059640 + A0 * 4] = w(A1);
[GP + 1c0] = w(0);
////////////////////////////////



////////////////////////////////
// func322dc()
[GP + 1a8] = h(A0);
////////////////////////////////



////////////////////////////////
// func31f0c()
// looks like free memory
data = A0;
if( data == 0 )
{
    if( w[GP + 1c0] != 0 )
    {
        return 1;
    }

    [GP + 1cc] = w(0);
    [GP + 1d0] = w(RA - 8);

    A0 = 83;
    func19b50();
}

if( ( w[data - 4] & 02000000 ) == 0 )
{
    [data - 4] = w((w[data - 4] & 03ffffff) | 84000000); // remove 0xfc000000 and set it to 0x21
    [data - 4] = w(w[data - 4] & fe1fffff); // remove 0x01e00000
    [data - 4] = w(w[data - 4] & ffe00000); // remove 0x001fffff
    [GP + 1bc] = w(1);
    return 0;
}
else
{
    return -1;
}
////////////////////////////////
