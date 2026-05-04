function [mp]= define_motor_parameters(motor_model)
% initial values taken from: https://www.pololu.com/file/0J1487/pololu-micro-metal-gearmotors-rev-6-1.pdf

    switch motor_model
        case "1"
            mp.motor_ratio=29.86;
            mp.arm_induct=0.0100;% not given in specs
            mp.nlspeed=1100;
            mp.rotor_damp=5e-6;% not given in specs
            mp.rotor_I=2e-4;% not given in specs
            mp.stall_T=0.0441;
        case "2"
            mp.motor_ratio=51.45;
            mp.arm_induct=0.0100;% not given in specs
            mp.nlspeed=650;
            mp.rotor_damp=5e-6;% not given in specs
            mp.rotor_I=2e-4;% not given in specs
            mp.stall_T=0.0726;
        case "3"
            mp.motor_ratio=75.81;
            mp.arm_induct=0.0100;% not given in specs
            mp.nlspeed=430;
            mp.rotor_damp=5e-6;% not given in specs
            mp.rotor_I=2e-4;% not given in specs
            mp.stall_T=0.108;
    end
    
    %finally lets define some standard parameters for the PID controller
    mp.P = 15;
    mp.I = 400;
    mp.D = 0;
    mp.N = 100;
end