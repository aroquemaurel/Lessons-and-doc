/*
 * =====================================================================================
 *
 *       Filename:  instance.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 22:03:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __INSTANCE
#define __INSTANCE

typedef struct {
	double x;
	double y;
	int id;
}Instance;

void instance_display(const Instance pInstance);
void instance_initialize(Instance* pInstance);

#endif


