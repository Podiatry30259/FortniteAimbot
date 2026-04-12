// Aimbot was used for many months as an UD way to write camera angles offering a smooth aimbot 
// Because It got into the hands of some wrong people I dont want this to be sold or whatever so you can use it in your externals or internals
// I am stil using this in my private external but i am switching to a new input bypass because my bypass runs outside of memory
// if you need help updating just contact or create an issue and i will release the new one. 

// for SilentV2 you can go ahead and write angle then keep player rotation locked this will give that fake silent aim. 

void write_angles( uintptr_t view_matrix , f_rotation new_angles ) {
    uintptr_t rotation_ptr = read_memory( view_matrix + 0x102b );
    rotation_ptr = read_memory( rotation_ptr + 0x5c );

    uintptr_t rotation_sc = read_memory( rotation_ptr + 0x24 ); // if breaks each game update add 0x4 not for hotpatch

    writememory( rotation_sc, new_angles );
}
