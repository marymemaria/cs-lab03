#include "histogram.h"
#include "svg.h"
#include <cassert>

void test_positive() {
	double min = 0;
	double max = 0;
	find_minmax({ 1, 2, 3 }, min, max);
	assert(min == 1);
	assert(max == 3);
}

void test_negative() {
	double min = 0;
	double max = 0;
	find_minmax({ -1, -2, -3 }, min, max);
	assert(min == -3);
	assert(max == -1);
}

void test_different() {
	double min = 0;
	double max = 0;
	find_minmax({ 1, 1, 1 }, min, max);
	assert(min == 1);
	assert(max == 1);
}

void test_one() {
	double min = 0;
	double max = 0;
	find_minmax({ 1 }, min, max);
	assert(min == 1);
	assert(max == 1);
}

void test_empty() {
	double min = 0;
	double max = 0;
	find_minmax({  }, min, max);
	assert(min == 0);
	assert(max == 0);
}

void test_svg1() {
	const double text_width = 20;
	assert(calc_image_height(text_width) > 0);
};

void test_svg2() {
	const double text_width = -100;
	assert(calc_image_height(text_width) < 0);
};

int main() {
	test_positive();
	test_negative();
	test_different();
	test_one();
	test_empty();
	test_svg1();
	test_svg2;
}