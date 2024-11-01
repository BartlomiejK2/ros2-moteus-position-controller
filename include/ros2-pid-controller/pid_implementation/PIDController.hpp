#ifndef _PID_CONTROLLER_HPP_
#define _PID_CONTROLLER_HPP_

class PIDController
{
    private:

    /* Classic PID coefficients */
    double proportional_coef_;
    double derivative_coef_;
    double integral_coef_;

    /* Low-pass filter coefficient (used only for deravitave term) */
    double smoothing_factor_;

    /* Errors (for proportional and integral) and filterred errors (for derivative) */
    double errors_[2];
    double filtered_errors_[3];

    double calculateProportionalOutput(); // Biorą bledy juz z tablic wyzej
    double calculateIntegralOutput();
    double calculateDerivativeOutput();

    public:

    PIDController(double _p, double _d, double i, double _smoothing_factor);
    PIDController(const PIDController& other) = default;
    PIDController(PIDController&& other) = default;

    double calculateOutput(double _error, double _feedforward_input); //  Tutaj liczymy wszystko
};

#endif