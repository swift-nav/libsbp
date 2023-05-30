# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;
use Encode;

########################################################################
package Piksi;

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
package Piksi::MsgNetworkStateResp;

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

    $self->{ipv4_address} = ();
    my $n_ipv4_address = 4;
    for (my $i = 0; $i < $n_ipv4_address; $i++) {
        push @{$self->{ipv4_address}}, $self->{_io}->read_u1();
    }
    $self->{ipv4_mask_size} = $self->{_io}->read_u1();
    $self->{ipv6_address} = ();
    my $n_ipv6_address = 16;
    for (my $i = 0; $i < $n_ipv6_address; $i++) {
        push @{$self->{ipv6_address}}, $self->{_io}->read_u1();
    }
    $self->{ipv6_mask_size} = $self->{_io}->read_u1();
    $self->{rx_bytes} = $self->{_io}->read_u4le();
    $self->{tx_bytes} = $self->{_io}->read_u4le();
    $self->{interface_name} = Encode::decode("ascii", $self->{_io}->read_bytes(16));
    $self->{flags} = $self->{_io}->read_u4le();
}

sub ipv4_address {
    my ($self) = @_;
    return $self->{ipv4_address};
}

sub ipv4_mask_size {
    my ($self) = @_;
    return $self->{ipv4_mask_size};
}

sub ipv6_address {
    my ($self) = @_;
    return $self->{ipv6_address};
}

sub ipv6_mask_size {
    my ($self) = @_;
    return $self->{ipv6_mask_size};
}

sub rx_bytes {
    my ($self) = @_;
    return $self->{rx_bytes};
}

sub tx_bytes {
    my ($self) = @_;
    return $self->{tx_bytes};
}

sub interface_name {
    my ($self) = @_;
    return $self->{interface_name};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Piksi::NetworkUsage;

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

    $self->{duration} = $self->{_io}->read_u8le();
    $self->{total_bytes} = $self->{_io}->read_u8le();
    $self->{rx_bytes} = $self->{_io}->read_u4le();
    $self->{tx_bytes} = $self->{_io}->read_u4le();
    $self->{interface_name} = Encode::decode("ascii", $self->{_io}->read_bytes(16));
}

sub duration {
    my ($self) = @_;
    return $self->{duration};
}

sub total_bytes {
    my ($self) = @_;
    return $self->{total_bytes};
}

sub rx_bytes {
    my ($self) = @_;
    return $self->{rx_bytes};
}

sub tx_bytes {
    my ($self) = @_;
    return $self->{tx_bytes};
}

sub interface_name {
    my ($self) = @_;
    return $self->{interface_name};
}

########################################################################
package Piksi::MsgCommandResp;

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

    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{code} = $self->{_io}->read_s4le();
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub code {
    my ($self) = @_;
    return $self->{code};
}

########################################################################
package Piksi::MsgCommandOutput;

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

    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{line} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub line {
    my ($self) = @_;
    return $self->{line};
}

########################################################################
package Piksi::Latency;

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

    $self->{avg} = $self->{_io}->read_s4le();
    $self->{lmin} = $self->{_io}->read_s4le();
    $self->{lmax} = $self->{_io}->read_s4le();
    $self->{current} = $self->{_io}->read_s4le();
}

sub avg {
    my ($self) = @_;
    return $self->{avg};
}

sub lmin {
    my ($self) = @_;
    return $self->{lmin};
}

sub lmax {
    my ($self) = @_;
    return $self->{lmax};
}

sub current {
    my ($self) = @_;
    return $self->{current};
}

########################################################################
package Piksi::MsgThreadState;

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

    $self->{name} = Encode::decode("ascii", $self->{_io}->read_bytes(20));
    $self->{cpu} = $self->{_io}->read_u2le();
    $self->{stack_free} = $self->{_io}->read_u4le();
}

sub name {
    my ($self) = @_;
    return $self->{name};
}

sub cpu {
    my ($self) = @_;
    return $self->{cpu};
}

sub stack_free {
    my ($self) = @_;
    return $self->{stack_free};
}

########################################################################
package Piksi::MsgUartStateDepa;

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

    $self->{uart_a} = Piksi::UartChannel->new($self->{_io}, $self, $self->{_root});
    $self->{uart_b} = Piksi::UartChannel->new($self->{_io}, $self, $self->{_root});
    $self->{uart_ftdi} = Piksi::UartChannel->new($self->{_io}, $self, $self->{_root});
    $self->{latency} = Piksi::Latency->new($self->{_io}, $self, $self->{_root});
}

sub uart_a {
    my ($self) = @_;
    return $self->{uart_a};
}

sub uart_b {
    my ($self) = @_;
    return $self->{uart_b};
}

sub uart_ftdi {
    my ($self) = @_;
    return $self->{uart_ftdi};
}

sub latency {
    my ($self) = @_;
    return $self->{latency};
}

########################################################################
package Piksi::MsgNetworkStateReq;

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
package Piksi::MsgDeviceMonitor;

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

    $self->{dev_vin} = $self->{_io}->read_s2le();
    $self->{cpu_vint} = $self->{_io}->read_s2le();
    $self->{cpu_vaux} = $self->{_io}->read_s2le();
    $self->{cpu_temperature} = $self->{_io}->read_s2le();
    $self->{fe_temperature} = $self->{_io}->read_s2le();
}

sub dev_vin {
    my ($self) = @_;
    return $self->{dev_vin};
}

sub cpu_vint {
    my ($self) = @_;
    return $self->{cpu_vint};
}

sub cpu_vaux {
    my ($self) = @_;
    return $self->{cpu_vaux};
}

sub cpu_temperature {
    my ($self) = @_;
    return $self->{cpu_temperature};
}

sub fe_temperature {
    my ($self) = @_;
    return $self->{fe_temperature};
}

########################################################################
package Piksi::MsgMaskSatelliteDep;

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

    $self->{mask} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
}

sub mask {
    my ($self) = @_;
    return $self->{mask};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

########################################################################
package Piksi::MsgUartState;

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

    $self->{uart_a} = Piksi::UartChannel->new($self->{_io}, $self, $self->{_root});
    $self->{uart_b} = Piksi::UartChannel->new($self->{_io}, $self, $self->{_root});
    $self->{uart_ftdi} = Piksi::UartChannel->new($self->{_io}, $self, $self->{_root});
    $self->{latency} = Piksi::Latency->new($self->{_io}, $self, $self->{_root});
    $self->{obs_period} = Piksi::Period->new($self->{_io}, $self, $self->{_root});
}

sub uart_a {
    my ($self) = @_;
    return $self->{uart_a};
}

sub uart_b {
    my ($self) = @_;
    return $self->{uart_b};
}

sub uart_ftdi {
    my ($self) = @_;
    return $self->{uart_ftdi};
}

sub latency {
    my ($self) = @_;
    return $self->{latency};
}

sub obs_period {
    my ($self) = @_;
    return $self->{obs_period};
}

########################################################################
package Piksi::MsgSpecan;

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

    $self->{channel_tag} = $self->{_io}->read_u2le();
    $self->{t} = Gnss::GpsTime->new($self->{_io}, $self, $self->{_root});
    $self->{freq_ref} = $self->{_io}->read_f4le();
    $self->{freq_step} = $self->{_io}->read_f4le();
    $self->{amplitude_ref} = $self->{_io}->read_f4le();
    $self->{amplitude_unit} = $self->{_io}->read_f4le();
    $self->{amplitude_value} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{amplitude_value}}, $self->{_io}->read_u1();
    }
}

sub channel_tag {
    my ($self) = @_;
    return $self->{channel_tag};
}

sub t {
    my ($self) = @_;
    return $self->{t};
}

sub freq_ref {
    my ($self) = @_;
    return $self->{freq_ref};
}

sub freq_step {
    my ($self) = @_;
    return $self->{freq_step};
}

sub amplitude_ref {
    my ($self) = @_;
    return $self->{amplitude_ref};
}

sub amplitude_unit {
    my ($self) = @_;
    return $self->{amplitude_unit};
}

sub amplitude_value {
    my ($self) = @_;
    return $self->{amplitude_value};
}

########################################################################
package Piksi::MsgIarState;

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

    $self->{num_hyps} = $self->{_io}->read_u4le();
}

sub num_hyps {
    my ($self) = @_;
    return $self->{num_hyps};
}

########################################################################
package Piksi::MsgAlmanac;

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
package Piksi::MsgResetFilters;

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

    $self->{filter} = $self->{_io}->read_u1();
}

sub filter {
    my ($self) = @_;
    return $self->{filter};
}

########################################################################
package Piksi::UartChannel;

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

    $self->{tx_throughput} = $self->{_io}->read_f4le();
    $self->{rx_throughput} = $self->{_io}->read_f4le();
    $self->{crc_error_count} = $self->{_io}->read_u2le();
    $self->{io_error_count} = $self->{_io}->read_u2le();
    $self->{tx_buffer_level} = $self->{_io}->read_u1();
    $self->{rx_buffer_level} = $self->{_io}->read_u1();
}

sub tx_throughput {
    my ($self) = @_;
    return $self->{tx_throughput};
}

sub rx_throughput {
    my ($self) = @_;
    return $self->{rx_throughput};
}

sub crc_error_count {
    my ($self) = @_;
    return $self->{crc_error_count};
}

sub io_error_count {
    my ($self) = @_;
    return $self->{io_error_count};
}

sub tx_buffer_level {
    my ($self) = @_;
    return $self->{tx_buffer_level};
}

sub rx_buffer_level {
    my ($self) = @_;
    return $self->{rx_buffer_level};
}

########################################################################
package Piksi::MsgCommandReq;

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

    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{command} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub command {
    my ($self) = @_;
    return $self->{command};
}

########################################################################
package Piksi::MsgMaskSatellite;

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

    $self->{mask} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
}

sub mask {
    my ($self) = @_;
    return $self->{mask};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

########################################################################
package Piksi::MsgNetworkBandwidthUsage;

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

    $self->{interfaces} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{interfaces}}, Piksi::NetworkUsage->new($self->{_io}, $self, $self->{_root});
    }
}

sub interfaces {
    my ($self) = @_;
    return $self->{interfaces};
}

########################################################################
package Piksi::MsgReset;

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

    $self->{flags} = $self->{_io}->read_u4le();
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Piksi::MsgCellModemStatus;

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

    $self->{signal_strength} = $self->{_io}->read_s1();
    $self->{signal_error_rate} = $self->{_io}->read_f4le();
    $self->{reserved} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{reserved}}, $self->{_io}->read_u1();
    }
}

sub signal_strength {
    my ($self) = @_;
    return $self->{signal_strength};
}

sub signal_error_rate {
    my ($self) = @_;
    return $self->{signal_error_rate};
}

sub reserved {
    my ($self) = @_;
    return $self->{reserved};
}

########################################################################
package Piksi::MsgFrontEndGain;

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

    $self->{rf_gain} = ();
    my $n_rf_gain = 8;
    for (my $i = 0; $i < $n_rf_gain; $i++) {
        push @{$self->{rf_gain}}, $self->{_io}->read_s1();
    }
    $self->{if_gain} = ();
    my $n_if_gain = 8;
    for (my $i = 0; $i < $n_if_gain; $i++) {
        push @{$self->{if_gain}}, $self->{_io}->read_s1();
    }
}

sub rf_gain {
    my ($self) = @_;
    return $self->{rf_gain};
}

sub if_gain {
    my ($self) = @_;
    return $self->{if_gain};
}

########################################################################
package Piksi::MsgResetDep;

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
package Piksi::MsgSetTime;

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
package Piksi::MsgCwResults;

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
package Piksi::MsgSpecanDep;

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

    $self->{channel_tag} = $self->{_io}->read_u2le();
    $self->{t} = Gnss::GpsTimeDep->new($self->{_io}, $self, $self->{_root});
    $self->{freq_ref} = $self->{_io}->read_f4le();
    $self->{freq_step} = $self->{_io}->read_f4le();
    $self->{amplitude_ref} = $self->{_io}->read_f4le();
    $self->{amplitude_unit} = $self->{_io}->read_f4le();
    $self->{amplitude_value} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{amplitude_value}}, $self->{_io}->read_u1();
    }
}

sub channel_tag {
    my ($self) = @_;
    return $self->{channel_tag};
}

sub t {
    my ($self) = @_;
    return $self->{t};
}

sub freq_ref {
    my ($self) = @_;
    return $self->{freq_ref};
}

sub freq_step {
    my ($self) = @_;
    return $self->{freq_step};
}

sub amplitude_ref {
    my ($self) = @_;
    return $self->{amplitude_ref};
}

sub amplitude_unit {
    my ($self) = @_;
    return $self->{amplitude_unit};
}

sub amplitude_value {
    my ($self) = @_;
    return $self->{amplitude_value};
}

########################################################################
package Piksi::MsgInitBaseDep;

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
package Piksi::Period;

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

    $self->{avg} = $self->{_io}->read_s4le();
    $self->{pmin} = $self->{_io}->read_s4le();
    $self->{pmax} = $self->{_io}->read_s4le();
    $self->{current} = $self->{_io}->read_s4le();
}

sub avg {
    my ($self) = @_;
    return $self->{avg};
}

sub pmin {
    my ($self) = @_;
    return $self->{pmin};
}

sub pmax {
    my ($self) = @_;
    return $self->{pmax};
}

sub current {
    my ($self) = @_;
    return $self->{current};
}

########################################################################
package Piksi::MsgCwStart;

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

1;
