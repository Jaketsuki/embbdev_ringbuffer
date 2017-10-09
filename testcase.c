#include "ringbuffer.h"
uint8_t buffer_buf[MAX_BUFFER];
uint8_t data_table[MAX_BUFFER+10];
uint8_t buffer_string[MAX_BUFFER+10];
int16_t err;
struct buffer_type r;
uint8_t data_table_pos;

	
	
TEST(buffer_init,Test1)
{

	init_buffer(&r,buffer_buf);
	EXPECT_EQ(r.head,buffer_buf);
    EXPECT_EQ(r.tail,buffer_buf);
    EXPECT_EQ(r.buffer,buffer_buf);
	make_buffer(buffer_string);
}

TEST(buffer_empty,test2)
{
	r.tail+=5;
	empty_buffer(&r);
	EXPECT_EQ(r.head,r.tail);
}

TEST(buffer_status,test3)
{
init_buffer(&r,buffer_buf);
get_buffer_status(r,&err);
EXPECT_EQ(BUFFER_EMPTY,err);
r.head+=5;
EXPECT_EQ(5,get_buffer_status(r,&err));
empty_buffer(&r);
r.head+=-6;
EXPECT_EQ(-1,get_buffer_status(r,&err));
empty_buffer(&r);
r.head+=-500;
EXPECT_EQ(-1,get_buffer_status(r,&err));
empty_buffer(&r);
r.head+=+1000;
EXPECT_EQ(-1,get_buffer_status(r,&err));

}

TEST(add_char_to_buff,test4)
{
init_buffer(&r,buffer_buf);
add_char_to_buffer(&r,'C', &err);
EXPECT_EQ('C',*r.tail);
EXPECT_EQ('C',buffer_buf[0]);
}

TEST(get_char_from_buff,test5)
{
uint8_t from_buffer;
from_buffer=get_char_from_buffer(&r,&err);
EXPECT_EQ('C',from_buffer);
	
}


TEST(print16_t_buffer,test6)
{
	
	
}


TEST(add_string,test7)
{

	init_buffer(&r,buffer_buf);
	uint16_t i;
	uint8_t string[MAX_BUFFER]={'a','b', 'c','d','e','f','g'};
	add_string_to_buffer(&r, string, &err);
	//print16_t_buffer(r,&err);
	
}

TEST(get_string,test8)
{
	init_buffer(&r,buffer_buf);
	data_table_pos=0;
	uint16_t i;
	int16_t k,l;
	uint8_t j;
	uint8_t string[MAX_BUFFER];
	uint8_t string1[MAX_BUFFER]={'a','b', 'c','d','e','f','g'};
	//k=add_string_to_buffer(&r,string1, &err);
	k=add_string_to_buffer(&r,buffer_string, &err);
	l=get_string_from_buffer(&r,data_table,k, &err);
	for(j=0;j<=20;j++){
	printf("\n2. %d ",data_table[j]);}
}

/*
TEST(get_char_from_buff,test9)
{
	
}
*/
/*
TEST(get_char_from_buff,test10)
{
	
}
*/
/*
TEST(get_char_from_buff,test11)
{
	
}
*/
