%% STM32L4 Design Calculations (AN2867)
% designing oscillators using fundamental mode

format SHORTENG

% For the STM32L4, see page 29 of AN2867
g_m_min = 7.5e-3;
%g_m_min = 25e-3; % example in datasheet
G_m_crit_max = 1.5e-3;

% ECS-160-20-3X-TR (https://www.digikey.ca/en/products/detail/ecs-inc/ECS-160-20-3X-TR/2676606)
if 1 
    F = 16e6;
    C0 = 7e-12;
    CL = 20e-12;
    XESR_HSE = 50;
    PPM = 50; % stability PPM
    DL = 100e-6;
end

if 0 % example in datasheet
    F = 8e6;
    C0 = 7e-12;
    CL = 10e-12;
    XESR_HSE = 80;
end

Cs = 5e-12; % stray capacitance from layout (estimate for now)

% C_L = C_L1||C_L2 + Cs
% C_L1 = C_L2 -> C_L = C_L1/2 + Cs
% 2*(C_L - Cs) = C_L1
C_parallel = 2*(CL - Cs)

g_m_crit = 4*XESR_HSE*(2*pi*F)^2*(C0+CL)^2 % page 13 of AN2867
gain_margin = g_m_min/g_m_crit % should be >5

%F_standard = F*PPM/1e6

Radd_HSE = 1/(2*pi*F*C_parallel) % page 16 of AN2867
g_m_crit = 4*(XESR_HSE+Radd_HSE)*(2*pi*F)^2*(C0+CL)^2
gain_margin = g_m_min/g_m_crit % should be >5

% oscillator safety factor calculation (should be >= 5 for HSE and >= 3 for LSE)
Sf_HSE = (Radd_HSE+XESR_HSE)/XESR_HSE