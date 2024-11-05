# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Imu;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

}

########################################################################
package Imu::MsgImuRaw;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{tow_f} = $self->{_io}->read_u1();
    $self->{acc_x} = $self->{_io}->read_s2le();
    $self->{acc_y} = $self->{_io}->read_s2le();
    $self->{acc_z} = $self->{_io}->read_s2le();
    $self->{gyr_x} = $self->{_io}->read_s2le();
    $self->{gyr_y} = $self->{_io}->read_s2le();
    $self->{gyr_z} = $self->{_io}->read_s2le();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub tow_f {
    my ($self) = @_;
    return $self->{tow_f};
}

sub acc_x {
    my ($self) = @_;
    return $self->{acc_x};
}

sub acc_y {
    my ($self) = @_;
    return $self->{acc_y};
}

sub acc_z {
    my ($self) = @_;
    return $self->{acc_z};
}

sub gyr_x {
    my ($self) = @_;
    return $self->{gyr_x};
}

sub gyr_y {
    my ($self) = @_;
    return $self->{gyr_y};
}

sub gyr_z {
    my ($self) = @_;
    return $self->{gyr_z};
}

########################################################################
package Imu::MsgImuAux;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{imu_type} = $self->{_io}->read_u1();
    $self->{temp} = $self->{_io}->read_s2le();
    $self->{imu_conf} = $self->{_io}->read_u1();
}

sub imu_type {
    my ($self) = @_;
    return $self->{imu_type};
}

sub temp {
    my ($self) = @_;
    return $self->{temp};
}

sub imu_conf {
    my ($self) = @_;
    return $self->{imu_conf};
}

########################################################################
package Imu::MsgImuComp;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{time} = $self->{_io}->read_u8le();
    $self->{flags} = $self->{_io}->read_u2le();
    $self->{acc_comp_x} = $self->{_io}->read_s4le();
    $self->{acc_comp_y} = $self->{_io}->read_s4le();
    $self->{acc_comp_z} = $self->{_io}->read_s4le();
    $self->{gyr_comp_x} = $self->{_io}->read_s4le();
    $self->{gyr_comp_y} = $self->{_io}->read_s4le();
    $self->{gyr_comp_z} = $self->{_io}->read_s4le();
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub acc_comp_x {
    my ($self) = @_;
    return $self->{acc_comp_x};
}

sub acc_comp_y {
    my ($self) = @_;
    return $self->{acc_comp_y};
}

sub acc_comp_z {
    my ($self) = @_;
    return $self->{acc_comp_z};
}

sub gyr_comp_x {
    my ($self) = @_;
    return $self->{gyr_comp_x};
}

sub gyr_comp_y {
    my ($self) = @_;
    return $self->{gyr_comp_y};
}

sub gyr_comp_z {
    my ($self) = @_;
    return $self->{gyr_comp_z};
}

1;
