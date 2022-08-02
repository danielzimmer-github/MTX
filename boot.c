		//On start bios loads first 512 bytes into 
		//(segment, offset) (0x0, 0x7C00) e.g 0x7C00
		
		//We need to load the rest of the booter into memory then 
		//execute it
		//Then we need to load the operating system into memory after
		//finding it
		//
		//Computer starts in 16bit real mode, which means it can only
		//run 16-bit commands and access 1mb of memory

int tsize, dsize, ksectors, i, NSEC = 1;

int prints( char * s )
{
	while( *s ){ putc( *s++ ) ; }
}

int getsector(short sector)
{
	return readfd(sector/36, ((sector)%36)/18, (((sector)%36)%18));
}

int main()
{
	prints("Booting MTX OS\n\r");
	tsize = *(int*) (512+2);
	dsize = *(int*) (512+4);
	ksectors = ((tsize << 4) + dsize + 511)/512;
	setes(0x1000);
	for(i = 1; i <= ksectors+1; i++)
	{
		getsector(i);inces();putc(".");
	}
	prints("\n\rready to go?"); getc();
	return 0;
}

