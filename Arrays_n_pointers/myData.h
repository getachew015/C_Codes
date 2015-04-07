/*
 * myData.h
 *  Created on: Aug 29, 2014
 *      Author: dagim
 */
#define CUSTOMERS 7
#define PRODUCTS 6
#define MONTHS 12
#define TRUE 1

float totalShipped(const float shipped[CUSTOMERS][PRODUCTS][MONTHS]);
float catagCShipping(const float shipped[CUSTOMERS][PRODUCTS][MONTHS]);
float monthlyShipping(const float shipped[CUSTOMERS][PRODUCTS][MONTHS], int n);

//Input data for tones of products shipped
const float shippedOut[CUSTOMERS][PRODUCTS][MONTHS] =

{

{
{32.05,23.41,44.21,23.12,22.10,25.34,22.23,30.90,14.31,23.12,25.12,32.11},
{33.12,44.21,32.50,76.45,62.23,26.25,31.32,42.44,19.08,31.02,23.12,27.10},
{23.45,33.41,24.21,23.12,27.10,29.34,32.23,28.90,14.31,33.12,22.49,42.33},
{29.12,32.12,33.12,35.23,29.87,24.56,22.49,42.33,24.12,36.23,32.49,22.33},
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{29.12,32.12,33.12,45.23,29.87,24.56,22.49,28.33,34.12,26.23,27.49,42.33},
},

{
{33.12,44.21,32.50,76.45,62.23,26.25,31.32,42.44,19.08,31.02,23.12,27.10},
{23.45,33.41,24.21,23.12,27.10,29.34,32.23,28.90,14.31,33.12,22.49,42.33},
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,19.08},
{33.12,44.21,32.50,36.45,26.23,46.25,41.32,22.44,29.08,71.02,32.44,29.08},
{23.45,33.41,24.21,23.12,27.10,29.34,32.23,28.90,14.31,33.12,22.49,42.33},
},

{
{33.12,24.21,32.50,26.45,26.23,36.25,31.32,32.44,19.08,31.02,36.49,42.33},
{29.12,32.12,33.12,35.23,29.87,24.56,22.49,42.33,24.12,36.23,32.49,22.33},
{23.45,33.41,24.21,23.12,27.10,29.34,32.23,28.90,14.31,33.12,22.49,42.33},
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,19.08},
{32.05,23.41,44.21,23.12,22.10,25.34,22.23,30.90,14.31,23.12,25.12,32.11},
},

{
{23.45,33.41,24.21,23.12,27.10,29.34,32.23,28.90,14.31,33.12,22.49,42.33},
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,19.08},
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,19.08},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,19.08},
},

{
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{33.12,44.21,32.50,76.45,62.23,26.25,31.32,42.44,19.08,31.02,23.12,27.10},
{23.45,33.41,24.21,23.12,27.10,29.34,32.23,28.90,14.31,33.12,22.49,42.33},
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{23.45,33.41,24.21,23.12,27.10,29.34,32.23,28.90,14.31,33.12,22.49,42.33},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,69.08},
},

{
{23.45,33.41,24.21,23.12,27.10,29.34,32.23,28.90,14.31,33.12,22.49,42.33},
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,19.08},
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,29.08},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,39.08},
},

{
{33.12,24.21,32.50,26.45,26.23,36.25,31.32,32.44,19.08,31.02,36.49,42.33},
{29.12,32.12,33.12,35.23,29.87,24.56,22.49,42.33,24.12,36.23,32.49,22.33},
{23.45,33.41,24.21,23.12,27.10,29.34,32.23,28.90,14.31,33.12,22.49,42.33},
{30.12,24.21,29.50,26.45,26.23,26.25,31.32,32.44,19.08,31.02,42.49,32.33},
{29.12,32.12,100.90,45.23,29.87,34.56,42.49,20.33,44.12,86.23,32.44,19.08},
{32.05,23.41,44.21,23.12,22.10,25.34,22.23,30.90,14.31,23.12,25.12,32.11},
}

};

