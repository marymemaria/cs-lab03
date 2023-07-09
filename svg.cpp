#include "svg.h"

void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "balck") {
    cout << "<rect x = '" << x << "' y = '" << y << "' width = '" << width << "' height = '" << height
        << "' stroke = '" << stroke << "' fill = '" << fill << "'/>";
};

double calc_image_height(const double text_width) {
    double image_height = MAX_ASTERISK + text_width;
    return image_height;
};

void show_histogram_svg(const vector<size_t>& bins) {
    const auto TEXT_LEFT = 10;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 30;
    const auto BIN_WIDTH = 30;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = calc_image_height(TEXT_WIDTH);
    const auto MAX_BIN = *max_element(bins.begin(), bins.end());
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    svg_text(TEXT_LEFT, TEXT_BASELINE, to_string(bins[0]));
    svg_rect(0, TEXT_WIDTH, BIN_WIDTH, MAX_ASTERISK * (static_cast<double>(bins[0])) / MAX_BIN, "#FFFAF0", "#FFD700");
    double top = 0;
    for (size_t bin : bins) {
        const double bin_height = MAX_ASTERISK * (static_cast<double>(bin)) / MAX_BIN;
        svg_text(top + TEXT_LEFT, TEXT_BASELINE, to_string(bin));
        svg_rect(top, TEXT_WIDTH, BIN_WIDTH, bin_height, "#FFFAF0", "#FFD700");
        top += BIN_WIDTH;
    }
    svg_end();
}