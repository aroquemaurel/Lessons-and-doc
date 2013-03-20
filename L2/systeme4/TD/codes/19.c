int retourNieme(int fd,int n,int *err){
	int i;
	*err=0;
	*err=lseek(fd,sizeof(int)*(n-1),seek_set);
	if((*err)=-1 && read(fd,&i,sizeof(int)) != sizeof(int))
		*err=1;
	return i;

}

