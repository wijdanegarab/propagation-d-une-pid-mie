#include <stdio.h>
#include <math.h>

#define N 100
#define dt 0.03
#define DUREE_SIMULATION 30.0

void euler(double S[], double I[], double R[], double C[], double V[], double D[],
           double beta, double lambda, double mu, double nu, double pi, double population) {

    FILE *fp;
    fp = fopen("Pop.txt", "w");

    double t = 0.0;
    int i = 0;

    while (t <= DUREE_SIMULATION) {
        double dS = -beta * I[i] * S[i] - pi * S[i];
        double dC = beta * I[i] * S[i] - C[i] / nu;
        double dI = C[i] / nu - I[i] / lambda - mu * I[i];
        double dR = I[i] / lambda;
        double dV = pi * S[i] + dR;
        double dD = mu * I[i];

        S[i + 1] = fmax(0, S[i] + dS * dt);
        I[i + 1] = fmax(0, I[i] + dI * dt);
        R[i + 1] = fmax(0, R[i] + dR * dt);
        C[i + 1] = fmax(0, C[i] + dC * dt);
        V[i + 1] = fmax(0, V[i] + dV * dt);
        D[i + 1] = fmax(0, D[i] + dD * dt);

        
        fprintf(fp, "%lf %lf %lf %lf %lf %lf %lf %lf\n",
                t, S[i + 1], I[i + 1], R[i + 1], C[i + 1], V[i + 1], D[i + 1],
                S[i + 1] + I[i + 1] + R[i + 1] + C[i + 1] + V[i + 1] - D[i + 1]);

        t += dt;
        i++;
    }

    fclose(fp);
}

int main() {
    double S[N * N], I[N * N], R[N * N], C[N * N], V[N * N], D[N * N];

    double beta   = 0.5;
    double lambda = 12.0;
    double mu     = 0.05;
    double nu     = 10.0;
    double pi     = 0.1;
    double population = 1.0; 

    
    S[0] = 0.6 * population;
    I[0] = 0.1 * population;
    R[0] = 0.0;
    C[0] = 0.1 * population;
    V[0] = 0.2 * population;
    D[0] = 0.0;

    euler(S, I, R, C, V, D, beta, lambda, mu, nu, pi, population);

    return 0;
}
