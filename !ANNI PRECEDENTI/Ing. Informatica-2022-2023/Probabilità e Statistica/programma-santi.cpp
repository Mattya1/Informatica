#include <iostream>
#include <cmath>
#include <vector>

int main()
{

    std::vector<double> v, w;
    while(true) {
        int dim;
        long double x;
        std::cout << "specify the number of data: ";
        std::cin >> dim;
        std::cout << "Now submit the data:\n";
        long double s = 0;
        long double ss = 0;
        long double sw = 0;
        long double ssw = 0;
        long double sws = 0;
        for(int i = 0; i < dim; ++i) {
            std::cout << i + 1 << ": ";
            std::cin >> x;
            v.push_back(x);
            s += x;
            ss += x * x;
            if(w.size() > 0) {
                sw += w[i];
                ssw += w[i] * w[i];
                sws += w[i] * x;
            }
        }
        long double sxx = ssw - sw * sw / dim;
        long double syy = ss - s * s / dim;
        long double sxy = sws - s * sw / dim;
        long double B = sxy / sxx;
        long double A = (s / dim) - B * (sw / dim);
        long double ssr = (sxx * syy - sxy * sxy) / sxx;
        long double r2 = 1 - ssr / syy;
        std::cout << "\n\nsum: " << s << "\nmean: " << s / dim << "\nsum of squares: " << ss << "\nvariance (campionaria): " << (ss - s * s / dim) / (dim - 1) << "\nstandart deviation (campionaria): " << sqrt((ss - s * s / dim) / (dim - 1)) << "\nMLE variance: " << (ss - s * s / dim) / dim << "\nMLE standard deviation: " << sqrt((ss - s * s / dim) / dim) << "\nSxx/Syy: " << ss - s * s / dim << "\n\n";
        if(w.size() > 0) {
            std::cout << "Operations with two sets:\ncovariance: " << sxy / (dim - 1) << "\nSxy: " << sxy << "\nB: " << B << "\nA: " << A << "\nSSr: " << ssr << "\nR2: " << r2 << "\n\n";
        }
        w = v;
    }

return 0;
}