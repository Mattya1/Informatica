//d_array.h
#ifndef D_ARRAY_H
#define D_ARRAY_H

//****************************
// d_array.h
//****************************

//posso scrivere il codice anche in questo file, è questione di scelte e di ordine!
struct dynamic_array
{
	double *store;
	unsigned int size;
};

void read_d_array(dynamic_array &d);
void print_d_array(const dynamic_array &d);
void delete_d_array(dynamic_array &d);
void create_d_array(dynamic_array &d, int size, double value);
void set_d_element(dynamic_array &d, unsigned int index, double value);
double get_d_array_element(const dynamic_array &d, unsigned int index);
void concat_d_arrays (const dynamic_array &t1, const dynamic_array &t2, dynamic_array &t3);
void sort_d_array(dynamic_array &d);

#endif